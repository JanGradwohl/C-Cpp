class Random
{
public:
	Random();
	int Next(void);              // = rand()
	int Next(int max);           // 0..max-1  	
	int Next(int min, int max);  // >= min && < max	
};
