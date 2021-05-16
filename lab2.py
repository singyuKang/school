#201614792 컴퓨터공학과 강신규
#이 프로그램은 Login system 프로그램입니다


userlist ={} #유저의 정보를 딕셔너리를 사용하여 저장한다

while True:
    name = input("Login:") 

    if name == 'quit': #프로그램을 종료
        break

    if(name not in userlist):   #새로운 유저가 등장할때 새로운 패스워드를 저장한다
        userlist[name] = input("enter a new password:")
        
    else:   #기존유저가 등장할때 맞는패스워드를 입력하면 로그인성공 아니면 실패를 출력한다
        realpassword = input("enter yout password:")
        if (userlist[name]==realpassword):
            print("로그인 되었습니다")
        else:
            print("로그인에 실패하였습니다")
    
    
    
print("프로그램을 종료합니다")    
