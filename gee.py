import turtle

p= turtle.Pen()

a=600
k=1

for i in range(0,2000):
    p.forward(a)
    p.right(145)
    if(i>72*k-1):
        a+=200
        k+=1
