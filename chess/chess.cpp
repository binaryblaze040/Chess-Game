#include <bits/stdc++.h>
using namespace std;

char board[8][8];

void boardPrint()
{
	cout<<"-------------------------------------"<<endl;
	cout<<"    1  2  3  4  5  6  7  8\n\n";
	for(int i=0; i<8; i++)
	{
		cout<<i+1 <<"   ";
		for(int j=0; j<8; j++)
			cout <<board[i][j] <<"  ";

		cout<<endl;
	}
	cout<<"-------------------------------------"<<endl;
}

int validStep(int r, int c, int r1, int c1)
{
	int a=board[r][c]-0;
	int na=board[r1][c1]-0;

	//the selected box should be a non space char
	if(a==32)
	{
		cout<<"You should select a piece to move!\n";
		return 0;
	}

	//the player should move
	if(r==r1 && c==c1)
	{
		cout<<"You have to move a piece!\n";
		return 0;
	}

	//player should not step on his own piece
	if((a>100 && na>100) || (a<95 && (na<95 && na>64)))
	{
		cout<<"You can not step on your own piece!\n";
		return 0;
	}

	//pawn
	if(a==83 && r1==r+1)
	{
		if(c==c1 && board[r1][c1]==' ')
			return 1;

		if((c1==c+1 || c1==c-1) && na>100)
			return 1;
	}
	else if(a==115 && r1==r-1)
	{
		if(c==c1 && board[r1][c1]==' ')
			return 1;

		if((c1==c+1 || c1==c-1) && na<95 && na>64)
			return 1;
	}

	//rook
	else if(a==82 || a==114)
	{
		//Rook can change only one among row or column
		if(r1!=r && c1!=c)
			return 0;

		if(r1==r && c1!=c) //when column is changed
		{
			if(c1>c)
			{
				for(int i=c+1; i<c1; i++)
				{
					if(board[r][i]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(board[r1][c1]==' ' || (a==82 && na>100) || (a==114 && na<95))
					return 1;
			}
			else if(c1<c)
			{
				for(int i=c1+1; i<c; i++)
				{
					if(board[r][i]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(board[r1][c1]==' ' || (a==82 && na>100) || (a==114 && na<95))
					return 1;
			}
		}
		else if(c1==c && r1!=r) //when row is changed
		{
			if(r1>r)
			{
				for(int i=r+1; i<r1; i++)
				{
					if(board[i][c]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(board[r1][c1]==' ' || (a==82 && na>100) || (a==114 && na<95))
					return 1;
			}
			else if(r1<r)
			{
				for(int i=r1+1; i<r; i++)
				{
					if(board[i][c]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(board[r1][c1]==' ' || (a==82 && na>100) || (a==114 && na<95))
					return 1;
			}
		}
	}

	//knight
	else if(a==72)
	{
		if(((abs(r-r1)==2 && abs(c-c1)==1) || (abs(r-r1)==1 && abs(c-c1)==2)) && (na==32 || na>100))
			return 1;
	}
	else if(a==104)
	{
		if(((abs(r-r1)==2 && abs(c-c1)==1) || (abs(r-r1)==1 && abs(c-c1)==2)) && na<100)
			return 1;
	}

	//bishop
	else if(a==66)
	{
		if(abs(r1-r)==abs(c1-c))
		{
			if(r1<r && c1<c)
			{
				for(int i=r1+1, j=c1+1; i<r, j<c; i++, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na==32 || na>100)
					return 1;
			}
			else if(r1>r && c1>c)
			{
				for(int i=r+1, j=c+1; i<r1, j<c1; i++, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na==32 || na>100)
					return 1;
			}
			else if(r1<r && c1>c)
			{
				for(int i=r-1, j=c+1; i>r1, j<c1; i--, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na==32 || na>100)
					return 1;
			}
			else if(r1>r && c1<c)
			{
				for(int i=r+1, j=c-1; i<r1, j>c1; i++, j--)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na==32 || na>100)
					return 1;
			}
		}
	}
	else if(a==98)
	{
		if(abs(r1-r)==abs(c1-c))
		{
			if(r1<r && c1<c)
			{
				for(int i=r1+1, j=c1+1; i<r, j<c; i++, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na<95)
					return 1;
			}
			else if(r1>r && c1>c)
			{
				for(int i=r+1, j=c+1; i<r1, j<c1; i++, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na<95)
					return 1;
			}
			else if(r1<r && c1>c)
			{
				for(int i=r-1, j=c+1; i>r1, j<c1; i--, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na<95)
					return 1;
			}
			else if(r1>r && c1<c)
			{
				for(int i=r+1, j=c-1; i<r1, j>c1; i++, j--)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na<95)
					return 1;
			}
		}
	}

	//queen
	else if(a==81)
	{
		//bishop's movement
		if(abs(r1-r)==abs(c1-c))
		{
			if(r1<r && c1<c)
			{
				for(int i=r1+1, j=c1+1; i<r, j<c; i++, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na==32 || na>100)
					return 1;
			}
			else if(r1>r && c1>c)
			{
				for(int i=r+1, j=c+1; i<r1, j<c1; i++, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na==32 || na>100)
					return 1;
			}
			else if(r1<r && c1>c)
			{
				for(int i=r-1, j=c+1; i>r1, j<c1; i--, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na==32 || na>100)
					return 1;
			}
			else if(r1>r && c1<c)
			{
				for(int i=r+1, j=c-1; i<r1, j>c1; i++, j--)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na==32 || na>100)
					return 1;
			}
		}

		//rook's movement
		else if(r1==r && c1!=c) //when column is changed
		{
			if(c1>c)
			{
				for(int i=c+1; i<c1; i++)
				{
					if(board[r][i]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(board[r1][c1]==' ' || na>100)
					return 1;
			}
			else if(c1<c)
			{
				for(int i=c1+1; i<c; i++)
				{
					if(board[r][i]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(board[r1][c1]==' ' || na>100)
					return 1;
			}
		}
		else if(c1==c && r1!=r) //when row is changed
		{
			if(r1>r)
			{
				for(int i=r+1; i<r1; i++)
				{
					if(board[i][c]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(board[r1][c1]==' ' || na>100)
					return 1;
			}
			else if(r1<r)
			{
				for(int i=r1+1; i<r; i++)
				{
					if(board[i][c]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(board[r1][c1]==' ' || na>100)
					return 1;
			}
		}
	}
	else if(a==113)
	{
		//bishop's movement
		if(abs(r1-r)==abs(c1-c))
		{
			if(r1<r && c1<c)
			{
				for(int i=r1+1, j=c1+1; i<r, j<c; i++, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na<95)
					return 1;
			}
			else if(r1>r && c1>c)
			{
				for(int i=r+1, j=c+1; i<r1, j<c1; i++, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na<95)
					return 1;
			}
			else if(r1<r && c1>c)
			{
				for(int i=r-1, j=c+1; i>r1, j<c1; i--, j++)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na<95)
					return 1;
			}
			else if(r1>r && c1<c)
			{
				for(int i=r+1, j=c-1; i<r1, j>c1; i++, j--)
				{
					if(board[i][j]!=' ')
						return 0;
				}
				if(na<95)
					return 1;
			}
		}

		//rook's movement
		else if(r1==r && c1!=c) //when column is changed
		{
			if(c1>c)
			{
				for(int i=c+1; i<c1; i++)
				{
					if(board[r][i]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(na<95)
					return 1;
			}
			else if(c1<c)
			{
				for(int i=c1+1; i<c; i++)
				{
					if(board[r][i]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(na<95)
					return 1;
			}
		}
		else if(c1==c && r1!=r) //when row is changed
		{
			if(r1>r)
			{
				for(int i=r+1; i<r1; i++)
				{
					if(board[i][c]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(na<95)
					return 1;
			}
			else if(r1<r)
			{
				for(int i=r1+1; i<r; i++)
				{
					if(board[i][c]!=' ')
						return 0;
				}
				//to move box must be empty or rival's box
				if(na<95)
					return 1;
			}
		}
	}

	//king
	else if(a==75)
	{
		if(abs(r-r1)<2 && abs(c-c1)<2 && (na==32 || na>100))
			return 1;
	}
	else if(a==107)
	{
		if(abs(r-r1)<2 && abs(c-c1)<2 && na<100)
			return 1;
	}
	return 0;
}

int main()
{
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
			board[i][j]=' ';
	}

	//white
	board[0][0]='R';
	board[0][1]='H';
	board[0][2]='B';
	board[0][3]='Q';
	board[0][4]='K';
	board[0][5]='B';
	board[0][6]='H';
	board[0][7]='R';

	//black
	board[7][0]='r';
	board[7][1]='h';
	board[7][2]='b';
	board[7][3]='q';
	board[7][4]='k';
	board[7][5]='b';
	board[7][6]='h';
	board[7][7]='r';

	//soilders
	int t=1;
	for(int i=0; i<8; i++)
		board[t][i]='S';
	
	t=6;
	for(int i=0; i<8; i++)
		board[t][i]='s';

	//game start
	while(1)
	{
		int r, c, r1, c1;
		int valid;
		boardPrint();

		// player1 move
		while(1)
		{
			while(1)
			{
				cout<<"Player1:\n Enter row(1-8): ";
				cin>>r;
				if(r>0 && r<9)
					break;
				else
					cout<<"\nPlease enter a value between 1 to 8\n";
			}
			while(1)
			{
				cout<<" Enter column(1-8): ";
				cin>>c;
				if(c>0 && c<9)
					break;
				else
					cout<<"\nPlease enter a value between 1 to 8\n";
			}
			r--;
			c--;

			if(board[r][c]>100)
			{
				cout<<"Connot move other player's piece\n";
				continue;
			}

			while(1)
			{
				cout<<" Enter the row(where to move): ";
				cin>>r1;
				if(r1>0 && r1<9)
					break;
				else
					cout<<"\nPlease enter a value between 1 to 8\n";
			}
			while(1)
			{
				cout<<" Enter the column(where to move): ";
				cin>>c1;
				if(c1>0 && c1<9)
					break;
				else
					cout<<"\nPlease enter a value between 1 to 8\n";
			}
			r1--;
			c1--;

			valid=validStep(r, c, r1, c1);
			if(valid)
				break;
			else
				cout<<"Invalid Step! Enter Again:\n";
		}

		//check the game result
		if(board[r1][c1]=='k')
		{
			cout<<"\n        **Player1 won**\n";
			board[r1][c1]=board[r][c];
			board[r][c]=' ';
			boardPrint();
			break;
		}

		//moving
		board[r1][c1]=board[r][c];
		board[r][c]=' ';

		boardPrint();

		while(1)
		{
			// player2 move
			while(1)
			{
				cout<<"Player2:\n Enter row(1-8): ";
				cin>>r;

				if(r>0 && r<9)
					break;
				else
					cout<<"\nPlease enter a value between 1 to 8\n";
			}
			while(1)
			{
				cout<<" Enter column(1-8): ";
				cin>>c;
				if(c>0 && c<9)
					break;
				else
					cout<<"\nPlease enter a value between 1 to 8\n";
			}
			r--;
			c--;

			if(board[r][c]<100 && board[r][c]>65)
			{
				cout<<"Cannot move other player's piece\n";
				continue;
			}

			while(1)
			{
				cout<<" Enter the row(where to move): ";
				cin>>r1;
				if(r1>0 && r1<9)
					break;
				else
					cout<<"\nPlease enter a value between 1 to 8\n";
			}

			while(1)
			{
				cout<<" Enter the column(where to move): ";
				cin>>c1;
				if(c1>0 && c1<9)
					break;
				else
					cout<<"\nPlease enter a value between 1 to 8\n";
			}
			r1--;
			c1--;
			
			valid=validStep(r, c, r1, c1);
			if(valid)
				break;
			else
				cout<<"Invalid Step! Enter Again:\n";
		}
		//check the game result
		if(board[r1][c1]=='K')
		{
			cout<<"\n        **Player2 won**\n";
			board[r1][c1]=board[r][c];
			board[r][c]=' ';
			boardPrint();
			break;
		}

		//moving the piece
		board[r1][c1]=board[r][c];
		board[r][c]=' ';
	}
}