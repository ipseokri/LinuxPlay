#include <iostream>
#include <cstdio>
#include <cstdlib>

int front [4][4];
char back[4][4];
int k = 1;

void MakeRandom();
void MakeSet();
void ResetBack();
void ShowDown();
void PlayGame(); 
int IsThere(int input);
bool EndGame(void);

typedef struct Card{
	int row;
	int col;
} Card;

typedef struct Player{
	int Score;
} Player;

void Choice(Card c1, Card c2);

Player p1;
Player p2;
int Turn;

int main(void){
	ResetBack();
	int row, col;
	int select = 0;
	printf("1. 고정배치 , 2. 무작위 배치 : ");
	scanf("%d", &select);

	switch(select){
		case 1:
			MakeSet();
			ShowDown();
			PlayGame();
			break;
		case 2:
			MakeRandom();
			ShowDown();
			PlayGame();
			break;

	}
	
	return 0;
}


void ResetBack(){
	for(int i = 0; i < 4; i ++){
		for(int j = 0; j < 4; j ++){
			back[i][j] = 'x';
		}
	}
}

void MakeSet(){
	for(int i = 0; i < 4; i ++){
		for(int j = 0; j < 4; j ++){
			if(i < 2){
				front[i][j] = k;
				k++;
			}else{
				if(k > 8){
					k = 8;
				}
				front[i][j] = k;
				k--;
			}

		}
	}
	
}

void MakeRandom(){
	for(int i = 0; i < 4; i ++){
		for(int j = 0; j < 4; j++){
			while(1){
				int temp = rand()%8+1;
				if(IsThere(temp) == 0){
					front[i][j] = temp;
					break;
				}
			}
				
		}
	}
}

void ShowDown(){
	for(int i = 0; i < 4; i ++){
		for(int j = 0; j < 4; j ++){
			std::cout << back[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void PlayGame(){
	bool end = true;
	Card c1;
	Card c2;
	while(end){
		if(Turn %2 == 0){
			printf("Player 1 의 차례입니다. ");
		} else{
			printf("Player 2 의 차례입니다. ");
		}
		printf("카드 두개를 선택하세요 : ");
		scanf("%d %d %d %d", &c1.row, &c1.col, &c2.row, &c2.col);
		Choice(c1, c2);
		if(EndGame()){
			printf("게임이 종료되었습니다.\n");
			break;
		}
	}

	printf("Player 1 : %d, Player 2 : %d\n", p1.Score, p2.Score);
	if(p1.Score > p2.Score){
		printf("Player 1이 게임에서 이겼습니다.\n");
	} else if(p2.Score > p1.Score){
		printf("Player 2이 게임에서 이겼습니다.\n");
	} else{
		printf("점수가 같아 무승부입니다.");
	}
}

int IsThere(int input){
	int twice = 0;
	for(int i = 0; i < 4; i ++){
		for(int j = 0; j < 4; j++){
			if(front[i][j] == input){
				twice++;
			}
			if(twice == 2){
				return 1;
			}
		}
	}

	return 0;
}

void Choice(Card c1, Card c2){
	if(back[c1.row-1][c1.col-1] != 'x' | back[c2.row-1][c2.col-1] != 'x'){
		printf("이미 고른 카드입니다.\n");
		return;
	} else{
		if(front[c1.row-1][c1.col-1] == front[c2.row-1][c2.col-1]){
			if(Turn % 2 == 0){
				printf("Player 1이(가)");
				p1.Score += 1;
				if(front[c1.row-1][c1.col-1] == 7) p1.Score += 1;
			} else{
				printf("Player 2이(가)");
				p2.Score +=1;
				if(front[c1.row-1][c1.col-1] == 7) p2.Score += 1;
			}
			printf("플레이어가 점수를 획득하였습니다\n");
			back[c1.row-1][c1.col-1] = char(front[c1.row-1][c1.col-1]);
			back[c2.row-1][c2.col-1] = char(front[c2.row-1][c2.col-1]);
			Turn++;
		} else{
			printf("두장의 카드가 다릅니다. 점수를 획득하지 못했습니다.\n");
			Turn++;
		}
	}
	return;
}

bool EndGame(){
	for(int i = 0; i < 4; i ++){
		for(int j = 0; j < 4; j ++){
			if(back[i][j] == 'x'){
				return false;
			}
		}
	}

	return true;

}

