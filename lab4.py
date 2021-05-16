##201614792 컴퓨터공학과 강신규
##이프로그램은 그림을 그리는 프로그램입니다


from turtle import *
def drawStar():
    for i in range(0,5):
        forward(150)
        right(144)
def drawRectangle():
    for i in range(0,4):
        forward(150)
        right(90)
def drawTriangle():
    for i in range(0,3):
        forward(150)
        right(60)
def drawCircle():
    circle(100)
def menu():    
    print("welcome to Draw\n\n")
    print("\t s: draw a star")
    print("\t r: draw a rectangle")
    print("\t t:draw a triangle")
    print("\t c:draw a circle")
    print("\t u:utility")
    print("\t q:quit")
    choice = input("Your Choice:")##choice는 지역변수
    return choice

def utilityMenu():
    print("\t c:color")
    print("\t p:pen size")
    print("\t m:move pen location")
    utilityChoice = input("Your choice:")
    return utilityChoice

def penColor():
    print("원하시는 색깔을 고르세요")
    color = input("red or yellow")
    return color

    
def penSize(x):
    pensize(x)
    
    

def penLocation(x,y):
    penup()
    goto(x,y)
    pendown()



    
    
    

def probMenu():
    while True:
        choice = menu() ##앞에 choice는 다른 변수로 해도상관없다
        if choice == 'c':
            drawCircle()
        elif choice == 'r':
            drawRectangle()

        elif choice == 's':
            drawStar()
            
        elif choice == 't':
            drawTriangle()

        elif choice == 'u':
            utilityMenu()
            if utilityChoice == 'c':
                penColor()
                color(color)

            elif utilityChoice == 'p':
                penSize()

            elif utilityChoice == 'm':
                penlocation()

            else:
                break
           

        else:
            break
        
probMenu()

