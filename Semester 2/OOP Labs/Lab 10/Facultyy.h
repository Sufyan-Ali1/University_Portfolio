#pragma once
#include"Person.h"
class Facultyy:public Person
{
	
	private:
		int cnt;//Course count;
		int ext;//Extension
	public:
		int getage();
			
		int getext();
		void setext(int a);
		void setcnt(int a);
		int getcnt();

	
};

