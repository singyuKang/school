
import random

def drawBoard(info):
    print("-----------------")
    for i in info:        
        for j in i:          
                print("| ", j ," ",end="")
        print("|")
        print("-----------------")
#----------------------------------------------------------------------
def CheckWinner(info):
    winnerExist = False
    
    #Check Horizontal Lines    
    for i in range(3):
        if(info[i][0] != '   ' and info[i][0] == info[i][1] and info[i][1] == info[i][2]):
            winnerExist = True
    
    #Check Vertical Lines
    for i in range(3):
        if(info[0][i] != '   ' and info[0][i] == info[1][i] and info[1][i] == info[2][i]):
            winnerExist = True
           
    #Check Diagnal Lines
    if(info[i][0] != '   ' and info[0][0] == info[1][1] and info[1][1] == info[2][2]):
        winnerExist = True
    if(info[i][0] != '   ' and info[0][2] == info[1][1] and info[1][1] == info[2][0]):
        winnerExist = True

    return winnerExist
#------------------------------------------------------------------------

#this function returns string like "0,0" , "2,1"
def GetComputerDecide(info):
   #중앙이 비었는지 체크
    if(info[1][1] == '    '):
        return "1,1"
    else:
        #당장 지지 않기위해 막아햐 할곳을 체크
        result = GetBlankShouldFilled(info,' o ')
        if( result != ""):
            print("get not losing blank")
            return result
        else:
            #현재 놓으면 이길수 있는곳이 있는지 체크
            result = GetBlankShouldFilled(info,' X ')
            if( result != ""):
                print("get winning blank")
                return result
            else:
                #좋은 수가 없다면 랜덤으로 놓는다
                s = ""
                while True:
                    x = random.randint(0,2)
                    y = random.randint(0,2)
                    if( info[x][y] == '   '):
                        s = str(x)+","+str(y)
                        break
                print("get Raondom mark")
                return s
   
#--------------------------------------------------------------------------
def GetBlankShouldFilled(info,mark):
   #Find a Line that has two same mark    
    #Check in Horizontal Lines
    for i in range(3):
        count = 0
        empty = -1        
        for j in range(3):
            if ( info[i][j] == mark ):
                count+=1
            elif ( info[i][j] == '   ' ):
                empty = j
        if ( count == 2 ):
            if(empty != -1):
                print("horizontal")
                return str(i)+","+str(empty)
            
    #Check in Vertical Lines
    for i in range(3):
        count = 0
        empty = -1
        for j in range(3):
            if ( info[j][i] == mark ):
                count+=1
            elif ( info[j][i] == '   ' ):
                empty = j
        if ( count == 2 ):
            if(empty != -1):
                print("vertical")
                return str(empty)+","+str(i)

    #Check in Diagnal Lines
    count = 0
    empty = -1
    for i in range(3):
        if( info[i][i] == mark ):
            count+=1
        elif( info[i][i] == '   ' ):
            empty = i
    if(count == 2):
        if(empty != -1):
            print("diagnal")
            return str(empty)+","+str(empty)

    count = 0
    empty = -1
    for i in range(3):
        if( info[i][2-i] ==  mark ):
            count+=1
        elif( info[i][2-i] == '   ' ):
            empty = i

    if(count == 2):
        if(empty != -1):
            print("diagnal")
            return str(empty)+","+str(2-empty);

    return ""
#------------------------start Actual Code here-------------------------
info = [['   ','   ','   '],['   ','   ','   '],['   ','   ','   ']]
turn = 0

drawBoard(info)

while True:
    if(turn < 9):
        mark =''
        if(turn % 2 == 0):#when person's turn
            mark = 'o'

            #Get & Save input
            while True:
                cordinate = input("Player "+mark+" >>").split(',')
                x = int(cordinate[0])
                y = int(cordinate[1])

                if( x < 3 and y < 3):
                    if(info[x][y] =='   '):
                        info[x][y] = mark
                        break
                    else:
                        print("Already exist mark!")
                else:
                    print("input number under 3!!")
        else:#when computer's turn
            mark = 'X'
            cordinate = GetComputerDecide(info).split(',')
            print("Player X >> ",cordinate[0],",",cordinate[1])
            info[int(cordinate[0])][int(cordinate[1])] = mark

        #Draw Board
        drawBoard(info)
        
        #Check who is winner
        if(CheckWinner(info) == True ):
            print("The Winner is Player ",mark,"!!!")
            break
        
        turn+=1
    else:
        print("Winner doesn't EXIST!!")
        break;

    
