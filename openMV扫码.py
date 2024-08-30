import sensor,image
from machine import UART
from pyb import LED
import time
own_color = 1
red_led = LED(1)
green_led = LED(2)
blue_led = LED(3)
sensor.reset()
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(False)
uart1 = UART(1, 115200)
#while(True):
#    stm32_data = uart1.read()
#    if type(stm32_data) == bytes:
#        if(chr(stm32_data[0]) == 'Y'):
#            uart1.write(b'O')
#            green_led.on()
#            time.sleep_ms(10)
#            green_led.off()
#            break

clock = time.clock()
#识别优先级 中立>对方>己方
while(True):
    clock.tick()
    img = sensor.snapshot()
    tags = img.find_apriltags()
    if len(tags) == 0: #未识别到
                data = bytearray('000', 'utf-8')
                data = b'APN' + data + b'Y' + b'\n'
                uart1.write(data)
    else:
        priority_flag = 0
        for tag in tags:
            if tag.id() == 0:#中立
                x_position = tag.rect()[0] + tag.rect()[2]//2
                x1 = str(x_position // 100).encode('utf-8')
                x2 = str((x_position - (int(x1) * 100)) // 10).encode('utf-8')
                x3 = str(x_position % 10).encode('utf-8')
                data = b'APA' + x1 + x2 + x3 + b'Y' + b'\n'
                uart1.write(data)
#                print("中立->推")
                priority_flag = 1
                green_led.on()
                time.sleep_ms(1)
                green_led.off()
        if(priority_flag == 0):
            for tag in tags:
                if tag.id() != own_color: #敌方
                    x_position = tag.rect()[0] + tag.rect()[2]//2
                    x1 = str(x_position // 100).encode('utf-8')
                    x2 = str((x_position - (int(x1) * 100)) // 10).encode('utf-8')
                    x3 = str(x_position % 10).encode('utf-8')
                    data = b'APA' + x1 + x2 + x3 + b'Y' + b'\n'
                    uart1.write(data)
#                    print("敌方->推")
                    priority_flag = 1
                    green_led.on()
                    time.sleep_ms(1)
                    green_led.off()
        if(priority_flag == 0): #己方
            for tag in tags:
                x_position = tag.rect()[0] + tag.rect()[2]//2
                x1 = str(x_position // 100).encode('utf-8')
                x2 = str((x_position - (int(x1) * 100)) // 10).encode('utf-8')
                x3 = str(x_position % 10).encode('utf-8')
                data = b'APB' + x1 + x2 + x3 + b'Y' + b'\n'
                uart1.write(data)
#                print("己方->回避")
                red_led.on()
                time.sleep_ms(1)
                red_led.off()
    print("fps: ",clock.fps() )
