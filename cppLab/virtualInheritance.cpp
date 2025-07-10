

class base {
	protected:
	public :
		int a ;
		base(int i){ a = i;}
};

class left :  public base {
	public :
	left(int i) : base(i)
	{}

};
class right :  public base {
	public :
	right(int i) : base(i)
	{}

};

class bottom : public left, public right {
	public :

	bottom(int i) : base(i), left(10),  right(7)
	{

	}

};


int main()
{
	bottom first(100);
	std::cout << first.a << std::endl;

	// DiamondTrap a("Abari");
	// a.print();
	// a.attack("enemy");
}