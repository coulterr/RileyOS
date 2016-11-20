#include "../drivers/ps2/ps2_driver.h"
#include "../drivers/vga/vga_driver.h"
#include "../utils/utils.h"
#include "../utils/mem/mallocator.h"
#include "../utils/queue/char_queue.h"

int init_kernel()
{

	char_queue *ps2_queue = (char_queue *) mallocate(sizeof(char_queue) + sizeof(char) * 20); 
	char_queue_init(ps2_queue); 

	
	char_queue *vga_queue = (char_queue *) mallocate(sizeof(char_queue) + sizeof(char) * 20); 
	char_queue_init(vga_queue); 


	init_vga(); 
	vga_set_queue(vga_queue); 
	carriage_return(); 
	print_prompt(); 


	init_ps2(); 
	ps2_set_active_queue(ps2_queue); 
	ps2_set_vga_queue(vga_queue); 

	char_queue_enqueue(vga_queue, 'H'); 
	print_char(); 
	

	while(1)
	{
	}

}