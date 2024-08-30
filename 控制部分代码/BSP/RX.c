//#include "RX.h"
//#include "usart.h"

//int16_t temp=0,rest_count=0;
//float Temperature=0;
//float min_temp=500,max_temp=0;
//uint8_t data_buf[1544];
//static uint8_t search_x1=68,search_x2=4,search_y1=24,search_y2=0;
//uint8_t cen_x,cen_y;
//uint8_t flag_mlx,fire_judge;
//static char fire_flag;

//float myMap(float x, float in_min, float in_max, float out_min, float out_max)
//{
//    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
//}
//void rx_ans(uint8_t a,uint8_t b)
//{
//	if(a>=30&&a<=42)
//		flag_mlx=1;
//	else if(a<30)
//		flag_mlx=0;
//	else if(a>42)
//		flag_mlx=2;
//}
//void mlx(void)
//{
////        if(stata!=1)
////            continue ;
////        stata =0;
//        if(CHeck(data_buf))
//        {		
//            for(uint16_t y=0; y<24; y++)
//            {
//                for(uint16_t x=4; x<64+4; x=x+2)
//                {
//                    temp=((int16_t)data_buf[x+1+64*y]<<8|data_buf[x+64*y]);
//                    Temperature=(float)temp/100;
//                    if(Temperature>60)
//										{
//											fire_flag=1;
//											if(search_x1>x)
//												search_x1=x;
//											if(search_x2<x)
//												search_x2=x;
//											if(search_y1>y)
//												search_y1=y;
//											if(search_y2<y)
//												search_y2=y;								
//											//printf("**");
//										}                       
//                    //else
//											//printf("--");
//                }    
//              // printf("\r\n");
//            }
//						cen_x=(search_x1+search_x2)/2;
//						cen_y=(search_y1+search_y2)/2;
//						fire_judge=fire_flag;
//						rx_ans(cen_x,cen_y);
////					printf("%d,%d",cen_x,cen_y);
//						search_x1=68;search_x2=4;search_y1=24;search_y2=0;
//						fire_flag=0;
////					rest_count++;
////          printf("\r\n");
//     }
//}