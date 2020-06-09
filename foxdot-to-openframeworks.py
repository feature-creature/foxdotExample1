Server.add_forward("localhost",12345)

Clock.bpm = 40

Scale.default = Scale.major

print(Scale.names())

print(SynthDefs)

print(Attributes)

#b1 >> jbass([2,4,2,6],oct=[4,5,7],dur=2,pan=[-1,1],room=0.5,shape=0.25)
b1 >> jbass([2,4,2,6],oct=4)


#p1 >> play("k( ,S)",amplify=0.75)
p1 >> play("k ",amplify=0.5)

p2 >> play("Vv",dur=1/2,sus=4)

#p3 >> space(PRand(10),dur=[1/4],sus=[1/8],oct=[4,3],amp=0.5)
p3 >> space(10,dur=[1/4],oct=4,amp=0.5)

p5 >> creep([0,4,6,7,3,2],dur=1/2,sus=6, amplify=0.5)

c4 >> sawbass([2,[4,6]],dur=2)

#4 >> loop("nina2",dur=4,amplify=[0.75,0])
p4 >> loop("nina2",dur=4,amplify=0.75)



