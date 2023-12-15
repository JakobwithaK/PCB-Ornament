#include "Frames.h"

void amongus(){
  //grid_on();
  led_grid[0] = 000;
  led_grid[4] = 000;
  led_grid[10] = 000;
  led_grid[13] = 000;
  led_grid[18] = 000;

  while (0 == 0) {
    draw_frame();
  }
}

void happy(){
  //grid_on();
  led_grid[0] = 000;
  led_grid[2] = 000;
  led_grid[4] = 000;
  led_grid[5] = 000;

  led_grid[6] = 000;
  led_grid[8] = 000;

  led_grid[7] = 000;
  led_grid[9] = 000;
  led_grid[11] = 000;
  led_grid[12] = 000;
  led_grid[13] = 000;
  led_grid[15] = 000;
  led_grid[19] = 000;

  while (0 == 0) {
    draw_frame();
  }
}

void caution_lights(){
  int brightness = 0;
  int i =0;

  int delay = 0;
  while (0 == 0) {
// just do a number that counts from 0 to 100 then set the LED to that number. 
    if( delay >= 30){
      if (brightness < 101){  
          for(i=0; i<20; i++){
            led_grid[i]=led_grid[i] - 1;
          }
      }
      else{
          for(i=0; i<20; i++){
            led_grid[i]=led_grid[i] + 1;
          }
      }
      if (brightness < 201)
        brightness++;
      else
        brightness = 0;
      
      delay = 0;
    }
    draw_frame();

    delay++;
    
  }
}

void caution_lights2(){
  int i =0;
  int delay = 0;

  char multiplier[20] = {//learned with this that max char is 127, when we go over, the program errors out and stops.
  1, 2, 0, 1, 2,
  1, .75, 3, 2, 4,
  3, 1, 2, 0, 1,
  1, 2, 4, .5, 3,
  };

  int delta = 1;
  int brightness = 0;
  int max = 25;
  int min = 0;
  int speed = 100;

  while (0 == 0) {
// just do a number that counts from 0 to 100 then set the LED to that number. 
    if( delay >= speed){
      for(i=0; i<20; i++){
        led_grid[i]=brightness*multiplier[i] ;
      }

      brightness += delta;
      if(brightness == min || brightness == max) delta = -delta;
      delay = 0;
    }

    draw_frame();
    delay++;
    
  }
}

void snowflakes(){ 
  
  int delay = 0;

  srand(time(NULL));
  

  //snowflake1
  int brightness = 5;
  int delta = 1;
  int max = 100;
  int min = 1;
  int i =0;
  //second snowflake
  int brightness2 = 70;
  int delta2 = 1;
  int max2 = 100;
  int min2 = 1;
  int k =4;
  //second snowflake
  int brightness3 = 70;
  int delta3 = -1;
  int max3 = 100;
  int min3 = 1;
  int j =12;

  int speed = 40;
  for(i=0; i<20; i++){
    led_grid[i]=1;
  }

  while (0 == 0) {
// just do a number that counts from 0 to 100 then set the LED to that number. 
    if( delay >= speed){
      
      led_grid[i]=brightness;
      
      brightness += delta;
      if(brightness == min) {
        i = rand() % 20;
        delta = -delta;
      }
      else if (brightness == max) delta = -delta;

      //could just use 100-brightness to make it opposite

      //second snowflake
      led_grid[k]=brightness2;
      brightness2 += delta2;
      if(brightness2 == min2) {
        k = rand() % 20;
        delta2 = -delta2;
      }
      else if (brightness2 == max2) delta2 = -delta2;

      //third snowflake
      led_grid[j]=brightness3;
      brightness3 += delta3;
      if(brightness3 == min3) {
        j = rand() % 20;
        delta3 = -delta3;
      }
      else if (brightness3 == max3) delta3 = -delta3;

      delay = 0;
    }

    draw_frame();
    delay++;
    
  }
}

void snake_coil_uncoil(){
  
  int delay = 0;
  int curr_led =0, i=0;
  int speed = 150; //change this to set speed (higher is slower)
  int min = 0;
  int max = 20;
  int delta = -1;
  int brightness = 100;

  for(i=0; i<20; i++){//initialize lights
    led_grid[i]=0; //all off
  }
char order[20] = {0,1,2,3,4,9,14,19,18,17,16,15,10,5,6,7,8,13,12,11}; //order of lights turning on
  while (0 == 0) {
    if( delay >= speed){
      

      led_grid[order[curr_led]]=brightness;
      if(curr_led==max){
      delta = -delta;
      brightness=0;

      }
      else if (curr_led==min-1){
      delta = -delta;
      brightness=100;
      }
      curr_led+= delta;
      delay = 0;
    }
    draw_frame();
    delay++;
    
  }
}

void snake_coil(){
  
  int delay = 0;
  int i =0, k=0;
  int speed = 200; //change this to set speed

  for(i=0; i<20; i++){//initialize lights
    led_grid[i]=0; //all off
  }
char order[20] = {0,1,2,3,4,9,14,19,18,17,16,15,10,5,6,7,8,13,12,11}; //order of lights turning on
  while (0 == 0) {
    if( delay >= speed){
      
      if(i<20){
        led_grid[order[i]]=100;
        i++;
      }
      else{
        i=0;
        for(k=0; k<20; k++){//initialize lights
         led_grid[k]=0; //all off
        }
      }
      delay = 0;
    }
    draw_frame();
    delay++;
    
  }
}

//merry chri s  t  m  a  s
//12345 6789 10 11 12 13 14
void christmas(){ 
  int delay = 0;
  int curr_led =0, i=0;
  int speed = 2000; //change this to set speed (higher is slower)
 
  while (0 == 0) {
    if( delay >= speed){
      switch(i){
        case 1:
        case 12:
          M_(100);
          break;
        case 2:
          E_(100);
          break;
        case 3:
        case 4:
        case 8:
          R_(100);
          break;
        case 5:
          Y_(100);
          break;
        case 6:
          C_(100);
          break;
        case 7:
          H_(100);
          break;
        case 9:
          I_(100);
          break;
        case 10:
          S_(100);
          break;
        case 11:
          T_(100);
          break;
        case 13:
          A_(100);
          break;
        case 14: //last S has to be different
          S_(100);
          i=-1;
          break;
      }
    
    
      i++;
      delay=0;
    }
    draw_frame();
    delay++;

  }

}

void snake_slither(){
  
  int delay = 0;
  char curr_led =0, i=0;
  int speed = 150; //change this to set speed (higher is slower)
  char min = 0;
  char max = 51;
  char brightness = 100;
  int tail = 2, tail_end =2, little_count = 0, max_tail =7;

  for(i=0; i<20; i++){//initialize lights
    led_grid[i]=0; //all off
  }
char order[51] = {0,1,2,3,4,9,8,7,6,5,10,11,12,13,14,19,18,17,16,15,10,5,0,1,6,11,16,17,12,7,2,3,8,13,18,19,14,9,4,  0,1,2,3,8,13,12,7,6,11,10,5}; //order of lights turning on -43 entries
  while (0 == 0) {
    if( delay >= speed){
      led_grid[order[curr_led]]=brightness; //turn on front LED
      if(curr_led-tail >=0)//get rid of out of bounds error when looping
        led_grid[order[curr_led-tail]]=100-brightness; //turn off back LED
      if(curr_led-tail_end <0)
        //led_grid[order[curr_led+max-tail]]=100-brightness;
        led_grid[order[curr_led+max-tail_end]]=100-brightness;
      //else//turn off back LEDs when looping
      if(tail==1){
        if(curr_led-tail_end >=0)
          curr_led+=1;
        else if(little_count <max_tail){
          led_grid[order[little_count+max-tail_end]]=100-brightness;
          little_count++;
        }
        else if(little_count >=max_tail){
          curr_led+=1;
        }
      }
      else
        curr_led+= 1;
      if(curr_led==max){
        curr_led = 0;
        tail +=1;
        tail_end +=1;
        if (tail > max_tail){
          tail = 1;
          tail_end = max_tail;
        }
        if(tail==2){
          little_count = 0;
          tail_end = 2;
        }

      }
      
      delay = 0;
    }
    draw_frame();
    delay++;
    
  }
}
void snake_slither0(){ //tail length constant
  
  int delay = 0;
  int curr_led =0, i=0;
  int speed = 200; //change this to set speed (higher is slower)
  int min = 0;
  int max = 42;
  int brightness = 100;
  int tail = 4;

  for(i=0; i<20; i++){//initialize lights
    led_grid[i]=0; //all off
  }
char order[42] = {0,1,2,3,4,9,8,7,6,5,10,11,12,13,14,19,18,17,16,15,10,5,0,1,6,11,16,17,12,7,2,3,8,13,18,19,14,9,4,15,10,5}; //order of lights turning on -43 entries
  while (0 == 0) {
    if( delay >= speed){
      led_grid[order[curr_led]]=brightness; //turn on front LED
      if(curr_led-tail >=0)//get rid of out of bounds error when looping
        led_grid[order[curr_led-tail]]=100-brightness; //turn off back LED    
      else//turn off back LEDs when looping
        led_grid[order[curr_led+max-tail]]=100-brightness;
      curr_led+= 1;
      if(curr_led==max){
        curr_led = 0;
        

      }

      delay = 0;
    }
    draw_frame();
    delay++;
    
  }
}

void snake_coil_uncoil_fade(){
  
  int delay = 0;
  int curr_led =0, i=0;
  int speed = 200; //change this to set speed (higher is slower)
  int min = 0;
  int max = 19;
  int delta = 1;
  int brightness = 100;
  int tail = 4;

  for(i=0; i<20; i++){//initialize lights
    led_grid[i]=0; //all off
  }
char order[20] = {0,1,2,3,4,9,14,19,18,17,16,15,10,5,6,7,8,13,12,11}; //order of lights turning on
  while (0 == 0) {
    if( delay >= speed){
      
      
      led_grid[order[curr_led]]=brightness;
      if(curr_led-tail >=0)//get rid of out of bounds error
        led_grid[order[curr_led-tail]]=100-brightness;
      
      curr_led+= delta;
      if(curr_led==max+1){
        curr_led = max;
      delta = -delta;
      brightness=0;

      }
      else if (curr_led==min-1){
      delta = -delta;
      brightness=100;
      }
      
      delay = 0;
    }
    draw_frame();
    delay++;
    
  }
}


void snake_loading(){
  
  int delay = 0;
  int curr_led =0, i=0;
  int speed = 100; //change this to set speed (higher is slower)
  int min = 0;
  int max = 13;
  int delta = 1;
  int brightness = 100;
  int tail = 7;

  for(i=0; i<20; i++){//initialize lights
    led_grid[i]=0; //all off
  }
char order[20] = {0,1,2,3,4,9,14,19,18,17,16,15,10,5}; //order of lights turning on //0-13
  while (0 == 0) {
    if( delay >= speed){
      
      led_grid[order[curr_led]]=brightness;
      if(curr_led - tail >=0)//get rid of out of bounds error
        led_grid[order[curr_led - tail]]=100 - brightness;
      if(curr_led - tail <=0)//get rid of out of bounds error
        led_grid[order[max+curr_led - tail+1]]=100 - brightness;
      
      
      
      if(curr_led==max){
        curr_led = 0;
      }
      else
        curr_led+= delta;
      delay = 0;
    }
    draw_frame();
    delay++;
    
  }
}


void DVD_Logo(){
  
  int delay = 0;
  int curr_led =0, i=0;
  int speed = 150; //change this to set speed (higher is slower)
  
  int brightness = 100;
  

  for(i=0; i<20; i++){//initialize lights
    led_grid[i]=0; //all off
  }
char order[25] = {4,8,12,16,10,7,3,9,13,17,10,6,2,8,14,17,11,5,6,3,9,13,16,10,7}; //order of lights turning on //0-13
  while (0 == 0) {
    if( delay >= speed){
      
      if(i<25){
        led_grid[order[i]] = brightness;
        led_grid[order[i-1]] = 0;
        i++;
      }
      else{
        i=0;
        led_grid[order[i]] = brightness; 
        led_grid[order[24]] = 0;
        i++;
      }
      
      delay = 0;
    }
    draw_frame();
    delay++;
    
  }
}

void bug_random(){ 

  srand(time(NULL));  
  
  int delay = 0;
  int curr_led =0, i=0;
  int speed = 150; //change this to set speed (higher is slower)
  
  int brightness = 100;
  

  for(i=0; i<20; i++){//initialize lights
    led_grid[i]=0; //all off
  }
//char order[25] = {4,8,12,16,10,7,3,9,13,17,10,6,2,8,14,17,11,5,6,3,9,13,16,10,7}; //order of lights turning on //0-13
  while (0 == 0) {
    if( delay >= speed){
      
      led_grid[i] = 0;
      i = rand() % 20;
      led_grid[i] = brightness;

      delay = 0;
    }
    draw_frame();
    delay++;
    
  }
}
      
void bug_random_slow(){ 

  srand(time(NULL));  
  
  int delay = 0;
  int curr_led =0, i=0;
  int speed = 300; //change this to set speed (higher is slower)
  
  int brightness = 100;
  

  for(i=0; i<20; i++){//initialize lights
    led_grid[i]=0; //all off
  }
//char order[25] = {4,8,12,16,10,7,3,9,13,17,10,6,2,8,14,17,11,5,6,3,9,13,16,10,7}; //order of lights turning on //0-13
  while (0 == 0) {
    if( delay >= speed){
      
      led_grid[i] = 0;
      i = rand() % 20;
      led_grid[i] = brightness;

      delay = 0;
    }
    draw_frame();
    delay++;
    
  }
}

void snake_loading_2(){
  
  int delay = 0, i=0, k=0;
  int curr_led =0, curr_led2=0;
  int speed = 150; //change this to set speed (higher is slower)
  
  int max = 13, max2=6;
  
  int delta = 1;
  int brightness = 100;
  int brightness2 = 5;
  int tail = 6;
  int tail2 = 3;

  for(i=0; i<20; i++){//initialize lights
    led_grid[i]=0; //all off
  }
char order[20] = {0,1,2,3,4,9,14,19,18,17,16,15,10,5}; //order of lights turning on //0-13
//char order2[20] = {11,12,13,8,7,6}; //order of lights 2nd lights turning on //0-5
char order2[20] = {6,7,8,13,12,11, 20};

  while (0 == 0) {
    if( delay >= speed){
      
      led_grid[order[curr_led]] = brightness;
      if(curr_led - tail >=0)//get rid of out of bounds error
        led_grid[order[curr_led - tail]]=100 - brightness;
      if(curr_led - tail <=0)//get rid of out of bounds error
        led_grid[order[max+curr_led - tail+1]]=100 - brightness;
      
      
      
      if(curr_led==max){
        curr_led = 0;
      }
      else
        curr_led+= delta;
      
      //second loop
      //make it go at different speed
      if(k==1){
        led_grid[order2[curr_led2]] = brightness2;
        if(curr_led2 - tail2 >=0)//get rid of out of bounds error
          led_grid[order2[curr_led2 - tail2]]=5 - brightness2;
        if(curr_led2 - tail2 <=0)//get rid of out of bounds error
          led_grid[order2[max2+curr_led2 - tail2+1]]=5 - brightness2;
        if(curr_led2==max2){
          curr_led2 = 0;
        }
        else
          curr_led2+= delta;
      }
      else 
        k=0;
      k++;

      delay = 0;
    }
    draw_frame();
    delay++;
    
  }
}

void display_visualizer_frame(char char0, char char1, char char2, char char3, char char4){
// char[4] bar0 = {15,10,5,0};
// char bar0height =0;
// char[4] bar1 = {16,11,6,1};
// char bar1height =0;
// char[4] bar2 = {17,12,7,2};
// char bar2height =0;
// char[4] bar3 = {18,13,8,3};
// char bar3height =0;
// char[4] bar4 = {19,14,9,4};
// char bar4height =0;
  // char[4] bar0 = {15,10,5,0};
  // char[4] bar1 = {16,11,6,1};
  // char[4] bar2 = {17,12,7,2};
  // char[4] bar3 = {18,13,8,3};
  // char[4] bar4 = {19,14,9,4};
  char barheight[5] = {0,0,0,0,0};
  barheight[0] = char0;
  barheight[1] = char1;
  barheight[2] = char2;
  barheight[3] = char3;
  barheight[4] = char4;


  char bar_grid[5][4] = {
    {15,10,5,0},
    {16,11,6,1},
    {17,12,7,2},
    {18,13,8,3},
    {19,14,9,4}};
    // char bar_grid[5][4] = {
    // {0,5,10,15},
    // {1,6,11,16},
    // {2,7,12,17},
    // {3,8,13,18},
    // {4,9,14,19}};
  char i,k;
  for(k=0;k<5;k++){//bar (0,1,2,3,4)
    for(i=0;i<barheight[k];i++){  //height (0,1,2,3)
      led_grid[bar_grid[k][i]]=100;

    }

  }

}

// void visualizer(){ //terrible
  
//   int delay = 0;
//   char curr_led =0, i=0,k=0;
//   int speed = 200; //change this to set speed (higher is slower)
//   char min = 0;
//   char max = 51;
//   char brightness = 100;
//   int tail = 2, tail_end =2, little_count = 0, max_tail =7;

//   for(k=0; k<20; k++){//initialize lights
//     led_grid[k]=0; //all off
//   }
  
// char barheight[5] = {4,2,3,2,1};

//   while (0 == 0) {
//     if( delay >= speed){
//       for(k=0; k<20; k++){//initialize lights
//         led_grid[k]=0; //all off
//       }
//       draw_frame();

//       switch(i){
//         case 0: 
//           display_visualizer_frame(2,2,2,3,2);
//           break;
//         case 1:
//           display_visualizer_frame(2,2,2,3,3);
//           break;
//         case 2:
//           display_visualizer_frame(2,3,2,3,4);
//           break;
//         case 3:
//           display_visualizer_frame(2,2,2,3,3);
//           break;
//         case 4:
//           display_visualizer_frame(1,2,2,3,3);
//           break;
//         case 5:
//           display_visualizer_frame(1,2,2,3,3);
//           break;
//         case 6:
//           display_visualizer_frame(1,2,2,3,3);
//           break;
//         case 7:
//           display_visualizer_frame(1,3,2,3,4);
//           break;
//         case 8:
//           display_visualizer_frame(2,3,2,3,4);
//           break;
//         case 9:
//           display_visualizer_frame(2,2,2,4,4);
//           break;
//         case 10:
//           display_visualizer_frame(1,2,2,3,2);
//           break;
//         case 11:
//           display_visualizer_frame(1,2,2,2,2);
//           break;
//         case 12:
//           display_visualizer_frame(2,3,3,3,4);
//           break;
//         case 13:
//           display_visualizer_frame(2,3,4,3,4);
//           break;
//         case 14:
//           display_visualizer_frame(3,3,4,2,3);
//           break;
//         case 15:
//           display_visualizer_frame(3,3,4,1,3);
//           break;
//         case 16:
//           display_visualizer_frame(3,3,3,2,4);
//           break;
//         case 17:
//           display_visualizer_frame(2,3,3,3,4);
//           break;
//         case 18: //last S has to be different
//           display_visualizer_frame(2,2,2,3,2);
//           i=-1;
//           break;
        
//       }
    
//       i++;
//       delay=0;

//     }
//     draw_frame();
//     delay++;
    
//   }
// }



void wave(){
  int i =0, row=0;
  int delay = 0;
  int delta = 1;
  int brightness = 0;
  int max = 4;
  int min = 0;
  int speed = 500;
  grid_off();
  while (0 == 0) {
// just do a number that counts from 0 to 100 then set the LED to that number. 
    if( delay >= speed){
      
      for(i=row*5; i<((row * 5) + 5); i++){
        led_grid[i]= 13 * (row + 1) + (row + 1) * 10 * delta;
      }

      row += delta;
      if(row == min-1){
        delta = -delta;
        row=0;
      }
      else if(row == max) {
        delta = -delta;
        row = max - 1;
      }

      
      delay = 0;
    }

    draw_frame();
    delay++;
    
  }
}




void wave_continous(){
  int i =0, row=0 , pass=0;
  int delay = 0;
  
  int brightness = 0;
  int max = 4;
 
  int speed = 500;
  grid_off();
  while (0 == 0) {
// just do a number that counts from 0 to 100 then set the LED to that number. 
    if( delay >= speed){
      // if (pass == 0){
      //   for(i=row*5; i<((row * 5) + 5); i++){
      //     led_grid[i]= 100;
      //   }
      // }
      // else{
      //   for(i=row*5; i<((row * 5) + 5); i++){
      //     led_grid[i]= 10;
      //   }
          
      // }
      if (row==0){
        for(i=0; i<5; i++){
          led_grid[i]= 20;
        }
        for(i=5; i<10; i++){
          led_grid[i]= 2;
        }
        for(i=10; i<15; i++){
          led_grid[i]= 2;
        }
        for(i=15; i<20; i++){
          led_grid[i]= 2;
        }
      }
      else if (row==1){
        for(i=0; i<5; i++){
          led_grid[i]= 100;
        }
        for(i=5; i<10; i++){
          led_grid[i]= 2;
        }
        for(i=10; i<15; i++){
          led_grid[i]= 2;
        }
        for(i=15; i<20; i++){
          led_grid[i]= 2;
        }
      }
      else if (row==2){
        for(i=0; i<5; i++){
          led_grid[i]= 30;
        }
        for(i=5; i<10; i++){
          led_grid[i]= 100;
        }
        for(i=10; i<15; i++){
          led_grid[i]= 2;
        }
        for(i=15; i<20; i++){
          led_grid[i]= 2;
        }
      }
      else if (row==3){
        for(i=0; i<5; i++){
          led_grid[i]= 10;
        }
        for(i=5; i<10; i++){
          led_grid[i]= 30;
        }
        for(i=10; i<15; i++){
          led_grid[i]= 100;
        }
        for(i=15; i<20; i++){
          led_grid[i]= 2;
        }
        
     
      }
      else if (row==4){
        for(i=0; i<5; i++){
          led_grid[i]= 2;
        }
        for(i=5; i<10; i++){
          led_grid[i]= 10;
        }
        for(i=10; i<15; i++){
          led_grid[i]= 30;
        }
        for(i=15; i<20; i++){
          led_grid[i]= 100;
        }
      }
      else if (row==5){
        for(i=0; i<5; i++){
          led_grid[i]= 2;
        }
        for(i=5; i<10; i++){
          led_grid[i]= 2;
        }
        for(i=10; i<15; i++){
          led_grid[i]= 10;
        }
        for(i=15; i<20; i++){
          led_grid[i]= 30;
        }
      
      }
      else if (row==6){
        for(i=0; i<5; i++){
          led_grid[i]= 2;
        }
        for(i=5; i<10; i++){
          led_grid[i]= 2;
        }
        for(i=10; i<15; i++){
          led_grid[i]= 2;
        }
        for(i=15; i<20; i++){
          led_grid[i]= 10;
        }
        row = -1;
      }
      row += 1;
      
      // if(row == max) {
      //   row=0;
      //   pass ^= 1;
      // }
      
      delay = 0;
    }

    draw_frame();
    delay++;
    
  }
}


void A_(char brightness){

  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = 000;
  led_grid[7] = brightness;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = 000;
  led_grid[11] = 000;
  led_grid[12] = brightness;
  led_grid[13] = 000;
  led_grid[14] = brightness;

  led_grid[15] = brightness;
  led_grid[16] = brightness;
  led_grid[17] = brightness;
  led_grid[18] = brightness;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }


}
void B_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = 000;
  led_grid[7] = brightness;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = brightness;
  led_grid[11] = 000;
  led_grid[12] = brightness;
  led_grid[13] = 000;
  led_grid[14] = brightness;

  led_grid[15] = 000;
  led_grid[16] = brightness;
  led_grid[17] = 000;
  led_grid[18] = brightness;
  led_grid[19] = 000;

  // while (0 == 0) {
  //   draw_frame();
  // }

}

void C_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = 000;
  led_grid[7] = 000;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = brightness;
  led_grid[11] = 000;
  led_grid[12] = 000;
  led_grid[13] = 000;
  led_grid[14] = brightness;

  led_grid[15] = brightness;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }

}

void D_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = 000;
  led_grid[7] = 000;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = brightness;
  led_grid[11] = 000;
  led_grid[12] = 000;
  led_grid[13] = 000;
  led_grid[14] = brightness;

  led_grid[15] = 000;
  led_grid[16] = brightness;
  led_grid[17] = brightness;
  led_grid[18] = brightness;
  led_grid[19] = 000;

  // while (0 == 0) {
  //   draw_frame();
  // }

}

void E_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = 000;
  led_grid[7] = brightness;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = brightness;
  led_grid[11] = 000;
  led_grid[12] = brightness;
  led_grid[13] = 000;
  led_grid[14] = brightness;

  led_grid[15] = brightness;
  led_grid[16] = 000;
  led_grid[17] = brightness;
  led_grid[18] = 000;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}

void F_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = 000;
  led_grid[7] = brightness;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = 000;
  led_grid[11] = 000;
  led_grid[12] = 000;
  led_grid[13] = 000;
  led_grid[14] = brightness;

  led_grid[15] = 000;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = 000;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void G_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = 000;
  led_grid[7] = 000;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = brightness;
  led_grid[11] = 000;
  led_grid[12] = brightness;
  led_grid[13] = 000;
  led_grid[14] = brightness;

  led_grid[15] = brightness;
  led_grid[16] = brightness;
  led_grid[17] = brightness;
  led_grid[18] = 000;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void H_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = 000;
  led_grid[7] = brightness;
  led_grid[8] = 000;
  led_grid[9] = 000;

  led_grid[10] = 000;
  led_grid[11] = 000;
  led_grid[12] = brightness;
  led_grid[13] = 000;
  led_grid[14] = 000;

  led_grid[15] = brightness;
  led_grid[16] = brightness;
  led_grid[17] = brightness;
  led_grid[18] = brightness;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void I_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = 000;
  led_grid[2] = 000;
  led_grid[3] = 000;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = brightness;
  led_grid[7] = brightness;
  led_grid[8] = brightness;
  led_grid[9] = brightness;

  led_grid[10] = brightness;
  led_grid[11] = 000;
  led_grid[12] = 000;
  led_grid[13] = 000;
  led_grid[14] = brightness;

  led_grid[15] = 000;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = 000;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void J_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = 000;
  led_grid[2] = 000;
  led_grid[3] = 000;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = 000;
  led_grid[7] = 000;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = brightness;
  led_grid[11] = brightness;
  led_grid[12] = brightness;
  led_grid[13] = brightness;
  led_grid[14] = brightness;

  led_grid[15] = 000;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void K_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = 000;
  led_grid[7] = brightness;
  led_grid[8] = 000;
  led_grid[9] = 000;

  led_grid[10] = 000;
  led_grid[11] = brightness;
  led_grid[12] = 000;
  led_grid[13] = brightness;
  led_grid[14] = 000;

  led_grid[15] = brightness;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void L_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = 000;
  led_grid[7] = 000;
  led_grid[8] = 000;
  led_grid[9] = 000;

  led_grid[10] = brightness;
  led_grid[11] = 000;
  led_grid[12] = 000;
  led_grid[13] = 000;
  led_grid[14] = 000;

  led_grid[15] = 000;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = 000;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void M_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = 000;
  led_grid[7] = 000;
  led_grid[8] = brightness;
  led_grid[9] = 000;

  led_grid[10] = 000;
  led_grid[11] = 000;
  led_grid[12] = 000;
  led_grid[13] = brightness;
  led_grid[14] = 000;

  led_grid[15] = brightness;
  led_grid[16] = brightness;
  led_grid[17] = brightness;
  led_grid[18] = brightness;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void N_(char brightness){
  led_grid[0] = 000;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = 000;
  led_grid[7] = 000;
  led_grid[8] = brightness;
  led_grid[9] = 000;

  led_grid[10] = 000;
  led_grid[11] = 000;
  led_grid[12] = brightness;
  led_grid[13] = 000;
  led_grid[14] = 000;

  led_grid[15] = 000;
  led_grid[16] = brightness;
  led_grid[17] = brightness;
  led_grid[18] = brightness;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void O_(char brightness){
  led_grid[0] = 000;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = 000;

  led_grid[5] = brightness;
  led_grid[6] = 000;
  led_grid[7] = 000;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = brightness;
  led_grid[11] = 000;
  led_grid[12] = 000;
  led_grid[13] = 000;
  led_grid[14] = brightness;

  led_grid[15] = 000;
  led_grid[16] = brightness;
  led_grid[17] = brightness;
  led_grid[18] = brightness;
  led_grid[19] = 000;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void P_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = 000;
  led_grid[7] = brightness;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = 000;
  led_grid[11] = 000;
  led_grid[12] = 000;
  led_grid[13] = brightness;
  led_grid[14] = 000;

  led_grid[15] = 000;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = 000;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void Q_(char brightness){
  led_grid[0] = 000;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = brightness;
  led_grid[7] = 000;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = 000;
  led_grid[11] = brightness;
  led_grid[12] = brightness;
  led_grid[13] = brightness;
  led_grid[14] = brightness;

  led_grid[15] = brightness;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = 000;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void R_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = 000;
  led_grid[7] = brightness;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = 000;
  led_grid[11] = brightness;
  led_grid[12] = 000;
  led_grid[13] = brightness;
  led_grid[14] = 000;

  led_grid[15] = brightness;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = 000;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void S_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = 000;
  led_grid[2] = 000;
  led_grid[3] = brightness;
  led_grid[4] = 000;

  led_grid[5] = brightness;
  led_grid[6] = 000;
  led_grid[7] = brightness;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = brightness;
  led_grid[11] = 000;
  led_grid[12] = brightness;
  led_grid[13] = 000;
  led_grid[14] = brightness;

  led_grid[15] = 000;
  led_grid[16] = brightness;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void T_(char brightness){
  led_grid[0] = 000;
  led_grid[1] = 000;
  led_grid[2] = 000;
  led_grid[3] = 000;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = brightness;
  led_grid[7] = brightness;
  led_grid[8] = brightness;
  led_grid[9] = brightness;

  led_grid[10] = 000;
  led_grid[11] = 000;
  led_grid[12] = 000;
  led_grid[13] = 000;
  led_grid[14] = brightness;

  led_grid[15] = 000;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = 000;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void U_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = 000;
  led_grid[7] = 000;
  led_grid[8] = 000;
  led_grid[9] = 000;

  led_grid[10] = brightness;
  led_grid[11] = 000;
  led_grid[12] = 000;
  led_grid[13] = 000;
  led_grid[14] = 000;

  led_grid[15] = brightness;
  led_grid[16] = brightness;
  led_grid[17] = brightness;
  led_grid[18] = brightness;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void V_(char brightness){
  led_grid[0] = 000;
  led_grid[1] = 000;
  led_grid[2] = 000;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = brightness;
  led_grid[7] = brightness;
  led_grid[8] = 000;
  led_grid[9] = 000;

  led_grid[10] = brightness;
  led_grid[11] = brightness;
  led_grid[12] = brightness;
  led_grid[13] = 000;
  led_grid[14] = 000;

  led_grid[15] = 000;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = brightness;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void W_(char brightness){
  led_grid[0] = brightness;
  led_grid[1] = brightness;
  led_grid[2] = brightness;
  led_grid[3] = brightness;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = brightness;
  led_grid[7] = 000;
  led_grid[8] = 000;
  led_grid[9] = 000;

  led_grid[10] = 000;
  led_grid[11] = brightness;
  led_grid[12] = 000;
  led_grid[13] = 000;
  led_grid[14] = 000;

  led_grid[15] = brightness;
  led_grid[16] = brightness;
  led_grid[17] = brightness;
  led_grid[18] = brightness;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}
void X_(char brightness){
  led_grid[0] = 000;
  led_grid[1] = brightness;
  led_grid[2] = 000;
  led_grid[3] = 000;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = 000;
  led_grid[7] = brightness;
  led_grid[8] = brightness;
  led_grid[9] = 000;

  led_grid[10] = 000;
  led_grid[11] = 000;
  led_grid[12] = brightness;
  led_grid[13] = brightness;
  led_grid[14] = 000;

  led_grid[15] = 000;
  led_grid[16] = brightness;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}


void Y_(char brightness){

  led_grid[0] = 000;
  led_grid[1] = 000;
  led_grid[2] = 000;
  led_grid[3] = 000;
  led_grid[4] = brightness;

  led_grid[5] = brightness;
  led_grid[6] = brightness;
  led_grid[7] = brightness;
  led_grid[8] = brightness;
  led_grid[9] = 000;

  led_grid[10] = brightness;
  led_grid[11] = brightness;
  led_grid[12] = brightness;
  led_grid[13] = brightness;
  led_grid[14] = 000;

  led_grid[15] = 000;
  led_grid[16] = 000;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }

}

void Z_(char brightness){
  led_grid[0] = 000;
  led_grid[1] = brightness;
  led_grid[2] = 000;
  led_grid[3] = 000;
  led_grid[4] = brightness;

  led_grid[5] = 000;
  led_grid[6] = brightness;
  led_grid[7] = brightness;
  led_grid[8] = 000;
  led_grid[9] = brightness;

  led_grid[10] = 000;
  led_grid[11] = brightness;
  led_grid[12] = 000;
  led_grid[13] = brightness;
  led_grid[14] = brightness;

  led_grid[15] = 000;
  led_grid[16] = brightness;
  led_grid[17] = 000;
  led_grid[18] = 000;
  led_grid[19] = brightness;

  // while (0 == 0) {
  //   draw_frame();
  // }
}

void alphabet(){ //1568/8192 bytes
  int delay = 0;
  int curr_led =0, i=0;
  char brightness = 100;
  int speed = 1000; //change this to set speed (higher is slower)

  int (*p[26]) (char) = {A_, B_, C_, D_, E_, F_, G_, H_, I_, J_, K_, L_, M_, N_, O_, P_, Q_, R_, S_, T_, U_, V_, W_, X_, Y_,Z_};
  while (0 == 0) {
    if( delay >= speed){
      (*p[i]) (brightness);
      if(i==25)
        i=-1;
      i++;
      delay=0;
    }
    draw_frame();
    delay++;
  }
}

// void alphabet_switch(){ //1976/8192 bytes. Uses way more
//   int delay = 0;
//   int curr_led =0, i=0;
//   char brightness = 100;
//   int speed = 1000; //change this to set speed (higher is slower)


  
//   while (0 == 0) {
//     if( delay >= speed){
//       switch(i){
//         case 0:
//           A_(100);
//           break;
//         case 1:
//           B_(100);
//           break;
//         case 2:
//           C_(100);
//           break;
//         case 3:
//           D_(100);
//           break;
//         case 4:
//           E_(100);
//           break;
//         case 5:
//           F_(100);
//           break;
//         case 6:
//           G_(100);
//           break;
//         case 7:
//           H_(100);
//           break;
//         case 8:
//           I_(100);
//           break;
//         case 9:
//           J_(100);
//           break;
//         case 10:
//           K_(100);
//           break;
//         case 11:
//           L_(100);
//           break;
//         case 12:
//           M_(100);
//           break;
//         case 13:
//           N_(100);
//           break;
//         case 14:
//           O_(100);
//           break;
//         case 15:
//           P_(100);
//           break;
//         case 16:
//           Q_(100);
//           break;
//         case 17:
//           R_(100);
//           break;
//         case 18:
//           S_(100);
//           break;
//         case 19:
//           T_(100);
//           break;
//         case 20:
//           U_(100);
//           break;
//         case 21:
//           V_(100);
//           break;
//         case 22:
//           W_(100);
//           break;
//         case 23:
//           X_(100);
//           break;
//         case 24:
//           Y_(100);
//           break;
//         case 25:
//           Z_(100);
//           i=-1;
//           break;
//       }

//       i++;
//       delay=0;
//     }
//     draw_frame();
//     delay++;
//   }
// }
