#include <stdio.h>
#include <unistd.h>
#include <screen/screen.h>

#define WIDTH 800
#define HEIGHT 600

int main(){
	int status;
	screen_context_t ctx;
	screen_window_t win;
	int usage = SCREEN_USAGE_NATIVE;
	int num_buff = 2;
	status = screen_create_context(&ctx, 0);
	if(status != 0){
		printf("Couldn't make context");
		return 2;
	}
	status = screen_create_window(&win, ctx);
	if(status != 0){
		printf("Couldn't make window");
		return 2;
	}
	status = screen_set_window_property_iv(win, SCREEN_PROPERTY_USAGE, &usage);
	if(status != 0){
		printf("Couldn't make context");
		return 2;
	}
	screen_create_window_buffers(win, num_buff);
	int counter;
	while(1){
		/*
		 * we are using get_window render buffers in the loop because 
		 * this func returns them in order where available buffers are at the top of the 
		 * array, so each iteration, we get the ready buffer
		 *
		 *
		 */
		screen_buffer_t buff[2];
		//get the buffers from window buufers
		screen_get_window_property_pv(win, SCREEN_PROPERTY_RENDER_BUFFERS, (void **) buff);
		static uint32_t bg[3];
		if(counter <=120){
			bg[0] = SCREEN_BLIT_COLOR;
		    	bg[1] = 0xffff0000;
			bg[2] = SCREEN_BLIT_END;
		}else if(counter >120 && counter < 240){
			bg[0] = SCREEN_BLIT_COLOR;
		    	bg[1] = 0xff00ff00;
			bg[2] = SCREEN_BLIT_END;
		}else{	
			bg[0] = SCREEN_BLIT_COLOR;
		    	bg[1] = 0xff0000ff;
			bg[2] = SCREEN_BLIT_END;
		}
		if(counter<360){
			counter++;
		}else{
			counter = 0;
		}
		screen_fill(ctx, buff[0], bg);
		screen_post_window(win, buff[0], 0, NULL, 0);
		usleep(16666);
	}
	return 0;

}
