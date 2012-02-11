#ifndef __DRAW_LOADING_H_
#define __DRAW_LOADING_H_

#include "sdl_drawmode.h"

class draw_loading;
class load_ptr : public funcptr
{
	public:
		load_ptr(draw_loading *bla, int val);
		virtual void go();
	private:
		draw_loading *ref;
		int which;
};


class draw_loading : public sdl_drawmode
{
	public:
		draw_loading(sdl_user *self);
		~draw_loading();

		void update_load();
		void set_load_amount(int size);
		void add_loaded(int size);
		void load_done();
		int wait_server_pick();
		void server_picked(int i);
		
		virtual void mouse_click(SDL_MouseButtonEvent *here);
		virtual void mouse_to(SDL_MouseMotionEvent *to);
		virtual void mouse_from(SDL_MouseMotionEvent *from);
		virtual void mouse_move(SDL_MouseMotionEvent *from, SDL_MouseMotionEvent *to);
		virtual bool mouse_leave();	//is it ok for the mouse to leave?
		
		virtual bool quit_request();
	private:
		int load_progress;
		int load_amount;
		
		int num_servers;
		int server_pick;
		SDL_mutex *spick_mtx;
		bool quitting;
};

#endif