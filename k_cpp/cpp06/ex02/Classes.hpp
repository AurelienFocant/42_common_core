#ifndef CLASSES_HPP
#define CLASSES_HPP

class Base {
	public:
		virtual ~Base(){};
};

class A: public Base {
	public:
		~A(){};	// override
};

class B: public Base {
	public:
		~B(){};	// override
};

class C: public Base {
	public:
		~C(){};	// override
};

#endif // CLASSES_HPP
