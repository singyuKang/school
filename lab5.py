##201614792 컴퓨터공학과 강신규
##이 프로그램은 Tic tae toc 프로그램입니다

import random

def drawBoard(board):            ## 보드를 그리는 함수입니다
    print("-------------------")
    for i in board:        
        for j in i:          
                print("| ", j ," ",end="")
        print("|")


def CheckWinner(board):      ##이겼는지 졌는지 확인해주는 함수입니다 총8개의 이기는 경우의수가 있으며 가로3개 세로3개
                            ##대각선2개를 같은 마크가 채워져 있으면 True 을 반환 합니다
    winnerExist = False
       
    for i in range(3):
        if(board[i][0] != 'n' and board[i][0] == board[i][1] and board[i][1] == board[i][2]):
            winnerExist = True
    
   
    for i in range(3):
        if(board[0][i] != 'n' and board[0][i] == board[1][i] and board[1][i] == board[2][i]):
            winnerExist = True
           
    if(board[i][0] != 'n' and board[0][0] == board[1][1] and board[1][1] == board[2][2]):
        winnerExist = True
    if(board[i][0] != 'n' and board[0][2] == board[1][1] and board[1][1] == board[2][0]):
        winnerExist = True

    return winnerExist


def GetComputerDecide(board):  ##컴퓨터는 1순위로 가운데 2순위 안막으면 지는칸 3순위 이기는칸 4순위를 랜덤으로 우선순위를 둡니다
   ##중앙이 비었는지 체크합니다
    if(board[1][1] == 'n'):
        return "1,1"
    else:
        ##당장 지지 않기위해 막아햐 할곳을 체크합니다
        result = GetBlankShouldFilled(board,'X') 
        if( result != ""):
            return result
        else:
            ##현재 놓으면 이길수 있는곳이 있는지 체크합니다
            result = GetBlankShouldFilled(board,'o')
            if( result != ""):
                return result
            else:
               ##좋은 수가 없다면 랜덤으로 놓습니다
                s = ""
                while True:
                    x = random.randint(0,2)
                    y = random.randint(0,2)
                    if( board[x][y] == 'n'):
                        s = str(x)+","+str(y)
                        break
                return s
   
#--------------------------------------------------------------------------
def GetBlankShouldFilled(board,mark): ##같은 마크가 2개 있을때 수평수직대각선에 대하여 놓아야 할 위치를 반환해주는 함수입니다
    
    for i in range(3):      ##수평일때 놓아야할 위치를 반환해줍니다
        count = 0
        empty = -1        
        for j in range(3):
            if ( board[i][j] == mark ):
                count+=1
            elif ( board[i][j] == 'n' ):
                empty = j
        if ( count == 2 ):
            if(empty != -1):
                return str(i)+","+str(empty)
            
    for i in range(3):      ##수직일때 놓아야할 위치를 반환해줍니다
        count = 0
        empty = -1
        for j in range(3):
            if ( board[j][i] == mark ):
                count+=1
            elif ( board[j][i] == 'n' ):
                empty = j
        if ( count == 2 ):
            if(empty != -1):
                return str(empty)+","+str(i)

    count = 0
    empty = -1
    for i in range(3):   ##대각선일때 놓아야할 위치를 반환해줍니다
        if( board[i][i] == mark ):
            count+=1
        elif( board[i][i] == 'n' ):
            empty = i
    if(count == 2):
        if(empty != -1):
            return str(empty)+","+str(empty) ##좌표를 반환해줘야 됨으로 str으로 변환시켜 줍니다

    count = 0
    empty = -1
    for i in range(3):
        if( board[i][2-i] ==  mark ):
            count+=1
        elif( board[i][2-i] == 'n' ):
            empty = i

    if(count == 2):
        if(empty != -1):
            return str(empty)+","+str(2-empty);

    return ""


board = [['n','n','n'],['n','n','n'],['n','n','n']]
turn = 0

drawBoard(board)

while True:
    if(turn < 9):   ##총 9칸 이므로 9칸이 다찰때까지 이긴사람이 없으면 비기게 한다
        mark =''
        if(turn % 2 == 0):  #사람의 차례를 나타낸다
            mark = 'X'


            while True:
                cordinate = input("Player "+mark+" >>").split(',')
                x = int(cordinate[0])
                y = int(cordinate[1])

                if( x < 3 and y < 3):   ##3이상의 숫자를 입력할때 숫자를 다시받고 칸이 'n'일때만 mark를 채우도록한다
                    if(board[x][y] =='n'):
                        board[x][y] = mark
                        break
                    else:
                        print("Already exist mark!")
                else:
                    print("input number under 3!!")
        else:##컴퓨터의 차례를 나타낸다
            mark = 'o'
            cordinate = GetComputerDecide(board).split(',')
            print("Player o >> ",cordinate[0],",",cordinate[1])
            board[int(cordinate[0])][int(cordinate[1])] = mark

        drawBoard(board)
        
        
        if(CheckWinner(board) == True ):  ## 3칸이 다찼을때 이긴 사람을 출력해주고 loop을 빠져나온다
            print("The Winner is Player ",mark,"!!!")
            break
        
        turn+=1
    else:
        print("Winner doesn't EXIST!!")
        break;

    
