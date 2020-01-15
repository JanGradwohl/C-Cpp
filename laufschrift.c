#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define RIGHT 0
#define LEFT  1

void main(void)
{
	char text[] = "HALLO 2AHEL...............";
	char eingabe[] = "Hallo Sepp";
	char tmp;
	int waitingTime = 500;
	int len = strlen(text);      
		int len2 = strlen(eingabe);
	int dir = 0;  // 1 = rechts, 0 = links

	printf("len = %d\n", len);

	while (1) {
		printf("%s\r", text);

		if ( dir ) {
			tmp = text[len - 1];       // retten vom "rechtestem" Feld

			for (int x = len - 1; x >= 0; x--) {    // shiften
				text[x] = text[x - 1];
			}

			text[0] = tmp;            // das Gerettete
		}
		else {

			tmp = text[0];
			for (int x = 0; x < len - 1; x++) {    // shiften
				text[x] = text[x + 1];
			}
			text[len - 1] = tmp;
		}
		Sleep(waitingTime);

		if (GetAsyncKeyState(VK_ESCAPE)) {   
			
				break;
		}

		if (GetAsyncKeyState(VK_UP)) {
			waitingTime += 50;
		}

		if (GetAsyncKeyState(VK_DOWN)) {
			if ( waitingTime > 100)
				waitingTime -= 50;

		}



		if (GetAsyncKeyState(VK_SPACE)) {   
			

				dir = !dir;

			//if (dir == 0) {
			//        dir = 1;
			//}
			//else {
			//        dir = 0;
			//}
		}


	}
	system("pause");
}