#FORMAT- c/cpp(0/1)_userid_questionid_subid.c/cpp

from django.shortcuts import render
from django.contrib.auth import authenticate, login, logout			#for login and logout authentication
from django.template import RequestContext
from models import Questions, Subid, Userprofile			#custom models
from django.contrib.auth.models import User				#for getting username
from django.db.models import Max
import os,subprocess, sys								#for handling files/directories
from random import randint
from datetime import datetime, timedelta
#from django.core..context_processors import csrf
import credenz.settings 
base=credenz.settings.BASE_DIR
starttime = datetime.now()
endtime = datetime.now()+timedelta(minutes=1)

#@csrf_exempt
def new_user(request):
    global endtime
    if(endtime>datetime.now()):
	    if request.method=='POST':
		if User.objects.filter(username=str(request.POST.get('uname'))).exists():
		    return render(request, 'signup.html',{'message':"User already exists."})
		else:
		    uname=request.POST.get('uname')
		    password=request.POST.get('passwd')
		    email=request.POST.get('email')
		    user = User.objects.create_user(username=str(uname), password=str(password), email=str(email))
		    Userprofile.objects.create(score=0,
		                               name1=request.POST.get('name1'),
		                               name2 = request.POST.get('name2'),
		                               contact = request.POST.get('contact'),
		                               college = request.POST.get('college'),
		                               reciept = request.POST.get('reciept'),
		                               user = user
		                               )
		    return render(request, 'login.html')
	    return render(request, 'signup.html')
    else:
        return render(request,'signup.html')

def user_login(request):
    global endtime
    if(endtime>datetime.now()):
		if request.method=="POST":
		    username = request.POST.get('username')				#gets username from text field
		    password = request.POST.get('password')				#gets password from password field
		    user = authenticate(username=username, password=password)	#checks for correct username and password
		    if user is not None:
		        login(request, user)					#to successfully log in
		        try:
		            os.mkdir(os.path.join(base,'users',str(request.user.id)))	#to create a user directory
		        except:
		            print("")				#if user already exists
		        q = Questions.objects.all()			#to dynamically display questions link in question_view page
		        return render(request, 'question_view.html',{'questions':q})
		    else:
		        return render(request, 'login.html',)	#if wrong username/password
    else:
        return render(request,'signup.html')

def question_list(request):								#for displaying questions
    global endtime
    if(endtime>datetime.now()):
		if request.method=="GET":
		    x = request.GET.get('x')					#gets question ID
		    obj=Questions.objects.get(id=x)				#to get question according to question ID
		    return render(request, 'qenter.html',{'obj':obj})
		return render(request, 'question_view.html',)
    else:
        return render(request,'signup.html')

def submit(request):								#for submit button in qenter.html
    global endtime
    if(endtime>datetime.now()):
		c=request.POST['choice']
		questionid = request.POST.get('qid')

		user = Userprofile.objects.get(user=request.user)
		q = Questions.objects.get(id=questionid)
		subobj = Subid.objects.create(user=request.user,qid=q)
		if request.POST:
		        try:
		            code = request.FILES['doc'].read()
		        except:
		            code=request.POST.get('user_code')			#to get user code

		if (str(c)=="c"):							#if radio button c is selected
		    tf=os.path.join(base,'submissions/'+str(request.user.id)+'_'+str(questionid)+'_'+str(subobj.subid)+'.c')	#File name and path
		    
		    										
		if (str(c)=="c++"):							#if radio button c++ is selected
		    tf=os.path.join(base,'submissions/'+str(request.user.id)+'_'+str(questionid)+'_'+str(subobj.subid)+'.cpp')    #File name and path
		    

		f=open(tf,'w+')							#creates and opens file
		f.write(str(code))					        								#write user code to file
		f.close()
		judge='/home/suhavan/credenz/judge/testos1.py'
		#os.chdir("/home/suhavan/credenz/users/%s"%(str(request.user.id)))			
		if os.access('/home/suhavan/credenz/users/%s/marks'%str(request.user.id), os.F_OK)==0:        
		    os.system('touch /home/suhavan/credenz/users/%s/marks'%str(request.user.id))
		os.system("python %s %s > /home/suhavan/credenz/users/%s/marks"%(judge,tf,request.user.id))  #get marks in marks 
		fd=open("/home/suhavan/credenz/users/%s/marks"%str(request.user.id),"r")
		r=fd.read()
		print(r)
		x=r.count('1')
		y=r.count('0')
		if 'error' in r:
		    print('Compile Time Error')
		
		else:
		    os.remove(os.path.join(base,'users/%s/a.out'%str(request.user.id)))
		    os.remove(os.path.join(base,'users/%s/marks'%str(request.user.id)))
		#for i in range(3):
		 #   t="i+1"+".uout"
		  #  os.remove(os.path.join(base,'users/%s/%s'%str(request.user.id,t))
		print(r)
		print(int(x))
		print(int(y))
		user.sub_no = user.sub_no + 1
		subobj.qscore = x
		subobj.save()
		try:
		    max_score = Subid.objects.filter(user=request.user,qid=questionid).aggregate(Max('qscore'))['qscore__max']
		except:
		    max_score=0
		
		if x >= int(max_score):
		    user.score += (x-int(max_score))
		    user.save()
		return render(request, 'resub.html')					#Return to 'Result Submitted' page
    else:
        return render(request,'signup.html')
def leaderboard(request):
    global endtime
    if(endtime>datetime.now()):
        king = Userprofile.objects.all().order_by('-score','sub_no')
        return render(request,'leaderboard.html',{'user':king})
    else:
        return render(request,'signup.html')
def log_out(request):      								#Logout user at anytime
	logout(request)
	return render(request,"signup.html")
        
        
