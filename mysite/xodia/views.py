from django.shortcuts import render
from models import UserData
from django.http import HttpResponseRedirect,HttpResponse
from django.core.urlresolvers import reverse
from os import path,chdir,system
from subprocess import Popen,PIPE
import mysite.settings
from django.contrib.auth import login,logout,authenticate
from django.contrib.auth.models import User
from django.contrib.auth.decorators import login_required
from django.views.decorators.csrf import csrf_exempt
import tempfile
# Create your views here.

def homepage(request):
	u = request.user
	if u.is_authenticated():
		return HttpResponseRedirect(reverse('xodia:personal_home'))
	else:
		return render(request,'xodia/index.html')
	
		

def signuppage(request):
	u = request.user
	if u.is_authenticated():
		return HttpResponseRedirect(reverse('xodia:personal_home'))
	else:
		return render(request,'xodia/login.html')
		

"""@csrf_exempt
def loginpage(request):
	u = request.user
	if u.is_authenticated():
		return HttpResponseRedirect(reverse('xodia:personal_home'))
	else:
		return render(request,'xodia/login.html')"""
		


def signup(request):
	u = request.user
	if u.is_authenticated():
		return HttpResponseRedirect(reverse('xodia:personal_home'))
	else:
		for exist_user in User.objects.all():
			if request.POST['uname'] == exist_user.username:
				return render(request,'xodia/alreadyuname.html')
    	
    	u = User.objects.create_user(username = request.POST['uname'] , first_name = request.POST['fname'] , last_name = request.POST['lname'] )
        u.email = request.POST['email']
    	u.set_password(request.POST['password'])
    	u.save()
    	ud  = UserData(user = u)
    	if 'dp' in request.FILES:
    		ud.profilepic  = request.FILES['dp']

    	else:
    		ud.profilepic  = path.join(mysite.settings.BASE_DIR,'static/xodia/dps/images_004.png')
    		#ud.profilepic = '/home/lite/xodia_web_engine/mysite/xodia/static/xodia/dps/11070092_1026956053989421_6069066535809089795_o.jpg'
    	ud.mobno = request.POST['mobno']
        ud.save()
    	print 'Before'
    	u.backend = 'django.contrib.auth.backends.ModelBackend'
    	login(request,u)
    	print 'After'
    	return HttpResponseRedirect(reverse('xodia:personal_home'))


    

def login_view(request):
    username = request.POST['uname']
    password = request.POST['password']

    """for u in User.objects.all():
    	if u.username == username:
    		if u.password == password:
    			flag = 1
    		else:
    			flag = 0
    	else:
    		flag=0"""

    u = authenticate(username = username , password = password)

    if u is not None:
    	if u.is_active:
    		#u.backend = 'django.contrib.auth.backends.ModelBackend'
    		login(request,u)
    		dppath = u.userdata.profilepic.name[len(mysite.settings.BASE_DIR) + 8:]
    		return HttpResponseRedirect(reverse('xodia:personal_home'))
    	else:
    		return HttpResponse("Not Active User")

    else: 
    	return render(request,'xodia/invalid_user_pwd.html')


@login_required(login_url='/')
def testpage(request,message=""):
	
	u = request.user
	if 'error' in request.session:
		message = request.session['error'] 
	print message
	request.session['error'] = ""
	dppath = u.userdata.profilepic.path[len(mysite.settings.BASE_DIR) + 8 :]
	acevalue1 = ""
	acevalue2 = ""
	acevaluef = ""	
	load_path =  path.join(mysite.settings.BASE_DIR,'xodiaxyz/playerone')
	
	if u.userdata.submitted == 1:
		bot_pathf = u.userdata.bot_pathf
		testfilef = path.join(load_path,bot_pathf)
		f = open(testfilef,'r')
		acevaluef = f.read()
		f.close() 


	elif u.userdata.test_no == 1:
		bot_path = u.userdata.bot_path1
		testfile = path.join(load_path,bot_path)
		f = open(testfile,'r')
		acevalue1 = f.read()
		f.close()
	elif u.userdata.test_no == 2:
		bot_path = u.userdata.bot_path2
		testfile = path.join(load_path,bot_path)
		f = open(testfile,'r')
		acevalue2 = f.read()
		f.close()

	elif u.userdata.test_no == 3:
		bot_path1 = u.userdata.bot_path1
		bot_path2 = u.userdata.bot_path2
		testfile1 = path.join(load_path,bot_path1)
		testfile2 = path.join(load_path,bot_path2)
		f = open(testfile1,'r')
		acevalue1 = f.read()
		f.close()
		f = open(testfile2,'r')
		acevalue2 = f.read()
		f.close()

	

	if u.userdata.submitted == 1:
		return render(request,'xodia/submitted.html',{'user':u ,'dppath':dppath , 'acevalue1': acevalue1 , 'acevalue2' : acevalue2, 'acevaluef':acevaluef ,'message': message })
	elif u.userdata.test_no == 0:
		return render(request,'xodia/test.html',{'user':u ,'dppath':dppath , 'acevalue1': acevalue1 , 'acevalue2' : acevalue2 ,'acevaluef':acevaluef , 'message' : message })
	elif u.userdata.test_no == 1 or u.userdata.test_no == 2 :
		return render(request,'xodia/test1.html',{'user':u ,'dppath':dppath , 'acevalue1': acevalue1 , 'acevalue2' : acevalue2 ,'acevaluef':acevaluef , 'message' : message })
	elif u.userdata.test_no == 3 :
		return render(request,'xodia/test2.html',{'user':u ,'dppath':dppath , 'acevalue1': acevalue1 , 'acevalue2' : acevalue2 ,'acevaluef':acevaluef ,'message' : message }) 
	
def logout_view(request):
	logout(request)
	return HttpResponseRedirect(reverse('xodia:homepage'))


@csrf_exempt    
@login_required(login_url = '/xodia/loginpage')
def personal_home(request):
	u = request.user
	dppath = u.userdata.profilepic.path[len(mysite.settings.BASE_DIR) + 8 :]
	return render(request,'xodia/indexlogged.html',{'user':u,'dppath':dppath})


def clickable(request):
	return render(request,'xodia/clickable.html')





"""def codeinput(request,user_id):
	action = request.POST.get('action')

	if action == 'test' :
		return HttpResponseRedirect(reverse('xodia:test', args=(user_id,)))

	if action == 'Submit' :
		return HttpResponseRedirect(reverse('xodia:submit', args=(user_id,))) """


def nolang(request):
	u = request.user
	if 'error' in request.session:
		message = request.session['error'] 
	print message
	request.session['error'] = ""
	dppath = u.userdata.profilepic.path[len(mysite.settings.BASE_DIR) + 8:]
	acevalue1 = ""
	acevalue2 = ""
	acevaluef = ""	
	load_path =  path.join(mysite.settings.BASE_DIR,'xodiaxyz/playerone/')
	if u.userdata.test_no == 1:
		bot_path = u.userdata.bot_path1
		testfile = path.join(load_path,bot_path)
		f = open(testfile,'r')
		acevalue1 = f.read()
		f.close()
	elif u.userdata.test_no == 2:
		bot_path = u.userdata.bot_path2
		testfile = path.join(load_path,bot_path)
		f = open(testfile,'r')
		acevalue2 = f.read()
		f.close()

	elif u.userdata.test_no == 3:
		bot_path1 = u.userdata.bot_path1
		bot_path2 = u.userdata.bot_path2
		testfile1 = path.join(load_path,bot_path1)
		testfile2 = path.join(load_path,bot_path2)
		f = open(testfile1,'r')
		acevalue1 = f.read()
		f.close()
		f = open(testfile2,'r')
		acevalue2 = f.read()
		f.close()

	elif u.userdata.submitted == 1:
		both_pathf = u.userdat.bot_pathf
		testfilef = path.join(load_path,bot_pathf)
		f = open(testfilef,'r')
		acvaluef = f.read()
		f.close() 


	
	if u.userdata.test_no == 0:
		return render(request,'xodia/nolang.html',{'user':u ,'dppath':dppath , 'acevalue1': acevalue1 , 'acevalue2' : acevalue2 ,'acevaluef':acevaluef , 'message' : message })
	elif u.userdata.test_no == 1 or u.userdata.test_no == 2 :
		return render(request,'xodia/nolang1.html',{'user':u ,'dppath':dppath , 'acevalue1': acevalue1 , 'acevalue2' : acevalue2 ,'acevaluef':acevaluef , 'message' : message })
	elif u.userdata.test_no == 3 :
		return render(request,'xodia/nolang2.html',{'user':u ,'dppath':dppath , 'acevalue1': acevalue1 , 'acevalue2' : acevalue2 ,'acevaluef':acevaluef ,'message' : message }) 
	elif u.userdata.submitted == 1:
		return render(request,'xodia/submitted.html',{'user':u ,'dppath':dppath , 'acevalue1': acevalue1 , 'acevalue2' : acevalue2, 'acevaluef':acevaluef ,'message': message })



@login_required(login_url = '/xodia/loginpage')
def test(request):
	u = request.user
	if u.is_authenticated():
		s = request.POST['code']
		test_no = request.POST['test_no']
		if u.userdata.test_no == 1 and test_no == 1 :
			del_path1 = '/var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playerone/'
			del_path2 = '/var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playertwo/'
			system('rm ' + del_path1 + str(u.userdata.bot_path1))
			system('rm ' + del_path2 + str(u.userdata.bot_path1))

		elif u.userdata.test_no == 2 and  test_no == 2 :
			del_path1 = '/var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playerone/'
			del_path2 = '/var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playertwo/'
			system('rm ' + del_path1 + str(u.userdata.bot_path2))
			system('rm ' + del_path2 + str(u.userdata.bot_path2))

		elif u.userdata.test_no == 3:
			if test_no == 1:
				del_path1 = '/var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playerone/'
				del_path2 = '/var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playertwo/'
				system('rm ' + del_path1 + str(u.userdata.bot_path1))
				system('rm ' + del_path2 + str(u.userdata.bot_path1))
			elif test_no == 2:
				del_path1 = '/var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playerone/'
				del_path2 = '/var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playertwo/'
				system('rm ' + del_path1 + str(u.userdata.bot_path2))
				system('rm ' + del_path2 + str(u.userdata.bot_path2))

				
		save_path1 = path.join(mysite.settings.BASE_DIR,'xodiaxyz/playerone/')
		save_path2 = path.join(mysite.settings.BASE_DIR,'xodiaxyz/playertwo/')

		if request.POST['lang'] == 's1':
			return HttpResponseRedirect(reverse('xodia:nolang'))
			

		elif request.POST['lang'] == 'c':
			if test_no == "test1" :
				u.userdata.bot_path1 = u.username + "test1" + ".c"
				bot_path = u.userdata.bot_path1
				if u.userdata.test_no == 2:
					u.userdata.test_no = 3
				elif u.userdata.test_no == 0:
					u.userdata.test_no = 1 
				
			elif test_no == "test2" :
				u.userdata.bot_path2 = u.username + "test2" + ".c"
				bot_path = u.userdata.bot_path2
				if u.userdata.test_no == 1:
					u.userdata.test_no = 3
				elif u.userdata.test_no == 0:
					u.userdata.test_no = 2
			

			elif test_no == "submit":
				u.userdata.bot_pathf = u.username + "final" + ".c"
				bot_path = u.userdata.bot_pathf
				u.userdata.submitted = 1

			
			file_path1 = path.join(save_path1,bot_path)
			file_path2 = path.join(save_path2,bot_path)
			f = open(file_path1,'w')
			f.write(str(s))
			f.close()
			f = open(file_path2,'w')
			f.write(str(s))
			f.close()
			with tempfile.TemporaryFile() as tempf :
				a = Popen('gcc '+ str(file_path1), shell = True ,stdout = PIPE , stderr = tempf)
				a.wait()
				tempf.seek(0)
				message = tempf.read()
				msg1=message.split("\n")
				ghi=0
				message=""
				while(ghi<len(msg1)):
					msg=msg1[ghi].split(":")
					gh=1
					st=""
					while(gh<len(msg)):
						if(msg[gh]!=""):
							st=st+msg[gh]
							if(gh!=len(msg)-1):
								st=st+":"
						gh=gh+1
					message = message+st
					if(st!=""):
						message=message+"\n"
					ghi=ghi+1
				
		
		elif request.POST['lang'] == 'cpp' :
			if test_no == "test1" :
				u.userdata.bot_path1 = u.username + "test1" + ".cpp"
				bot_path = u.userdata.bot_path1
				if u.userdata.test_no == 2:
					u.userdata.test_no = 3
				elif u.userdata.test_no == 0:
					u.userdata.test_no = 1 
				
			elif test_no == "test2" :
				u.userdata.bot_path2 = u.username + "test2" + ".cpp"
				bot_path = u.userdata.bot_path2
				if u.userdata.test_no == 1:
					u.userdata.test_no = 3
				elif u.userdata.test_no == 0:
					u.userdata.test_no = 2
			

			elif test_no == "submit" :
				u.userdata.bot_pathf = u.username + "final" + ".cpp"
				bot_path = u.userdata.bot_pathf
				u.userdata.submitted = 1
				

					
			file_path1 = path.join(save_path1,bot_path)
			file_path2 = path.join(save_path2,bot_path)
			f = open(file_path1,'w')
			f.write(str(s))
			f.close()
			f = open(file_path2,'w')
			f.write(str(s))
			f.close()
			with tempfile.TemporaryFile() as tempf :
				a = Popen('g++ -std=c++11 '+ str(file_path1), shell = True , stdout = PIPE , stderr = tempf)
				a.wait()
				tempf.seek(0)
				message = tempf.read()
				msg1=message.split("\n")
				ghi=0
				message=""
				while(ghi<len(msg1)):
					msg=msg1[ghi].split(":")
					gh=1
					st=""
					while(gh<len(msg)):
						if(msg[gh]!=""):
							st=st+msg[gh]
							if(gh!=len(msg)-1):
								st=st+":"
						gh=gh+1
					message = message+st
					if(st!=""):
						message=message+"\n"
					ghi=ghi+1

	
		elif request.POST['lang'] == 'java' :
			if test_no == "test1" :
				u.userdata.bot_path1 = u.username + "test1" + ".java"
				bot_path = u.userdata.bot_path1
				if u.userdata.test_no == 2:
					u.userdata.test_no = 3
				elif u.userdata.test_no == 0:
					u.userdata.test_no = 1 
				
			
			elif test_no == "test2" :
				u.userdata.bot_path2 = u.username + "test2" + ".java"
				bot_path = u.userdata.bot_path2
				if u.userdata.test_no == 1:
					u.userdata.test_no = 3
				elif u.userdata.test_no == 0:
					u.userdata.test_no = 2
			

			elif test_no == "submit" :
				u.userdata.bot_pathf = u.username + "final" + ".java"
				bot_path = u.userdata.bot_pathf
				u.userdata.submitted = 1
				
			
					
			file_path1 = path.join(save_path1,bot_path)
			file_path2 = path.join(save_path2,bot_path)

			f = open(file_path1,'w')
			f.write(str(s))
			f.close()
			f = open(file_path2,'w')
			f.write(str(s))
			f.close()
			with tempfile.TemporaryFile() as tempf :
				a = Popen('javac '+ str(file_path1), shell = True , stdout = PIPE , stderr = tempf)
				a.wait()
				tempf.seek(0)
				message = tempf.read()	
				msg1=message.split("\n")
				ghi=0
				message=""
				while(ghi<len(msg1)):
					msg=msg1[ghi].split(":")
					gh=1
					st=""
					while(gh<len(msg)):
						if(msg[gh]!=""):
							st=st+msg[gh]
							if(gh!=len(msg)-1):
								st=st+":"
						gh=gh+1
					message = message+st
					if(st!=""):
						message=message+"\n"
					ghi=ghi+1


		elif request.POST['lang'] == 'python' :
			if test_no == "test1" :
				u.userdata.bot_path1 = u.username + "test1" + ".py"
				bot_path = u.userdata.bot_path1
				if u.userdata.test_no == 2:
					u.userdata.test_no = 3
				elif u.userdata.test_no == 0:
					u.userdata.test_no = 1 
			

			elif test_no == "test2" :
				u.userdata.bot_path2 = u.username + "test2" + ".py"
				bot_path = u.userdata.bot_path2
				if u.userdata.test_no == 1:
					u.userdata.test_no = 3
				elif u.userdata.test_no == 0:
					u.userdata.test_no = 2

			
			elif test_no == "submit" :
				u.userdata.bot_pathf = u.username + "final" + ".py"
				bot_path = u.userdata.bot_pathf
				u.userdata.submitted = 1

					
			file_path1 = path.join(save_path1,bot_path)
			file_path2 = path.join(save_path2,bot_path)
			f = open(file_path1,'w')
			f.write(str(s))
			f.close()
			f = open(file_path2,'w')
			f.write(str(s))
			f.close()
			base = mysite.settings.BASE_DIR + "/python_compile.py"
			with tempfile.TemporaryFile() as tempf :
				a = Popen('python '+ str(base), shell = True , stdin = PIPE ,stdout = PIPE )
				message = a.communicate(input = file_path1)[0]
				msg = message.split('\n')
				msg = msg[1:]
				printmsg = ""
				for i in msg :
					if "," in i:
						i = i.split(",")[1]
					printmsg = printmsg + i + '\n'
				message = printmsg	

				
		elif request.POST['lang'] == 'python3' :
			if test_no == "test1" :
				u.userdata.bot_path1 = u.username + "test1" + "3.py"
				bot_path = u.userdata.bot_path1
				if u.userdata.test_no == 2:
					u.userdata.test_no = 3
				elif u.userdata.test_no == 0:
					u.userdata.test_no = 1 
			elif test_no == "test2" :
				u.userdata.bot_path2 = u.username + "test2" + "3.py"
				bot_path = u.userdata.bot_path2
				if u.userdata.test_no == 1:
					u.userdata.test_no = 3
				elif u.userdata.test_no == 0:
					u.userdata.test_no = 2

			elif test_no == "submit" :
				u.userdata.bot_pathf = u.username + "final" + "3.py"
				bot_path = u.userdata.bot_pathf
				u.userdata.submitted = 1


			base = mysite.settings.BASE_DIR + "/python_compile.py"	
			file_path1 = path.join(save_path1,bot_path)
			file_path2 = path.join(save_path2,bot_path)
			f = open(file_path1,'w')
			f.write(str(s))
			f.close()
			f = open(file_path2,'w')
			f.write(str(s))
			f.close()
			with tempfile.TemporaryFile() as tempf :
				a = Popen('python3.3 '+ str(base), shell = True , stdin = PIPE , stdout = PIPE )
				message = a.communicate(input = file_path1)[0]
				msg = message.split('\n')
				msg = msg[1:]
				printmsg = ""
				for i in msg :
					if "," in i:
						i = i.split(",")[1]
					printmsg = printmsg + i + '\n'
				message = printmsg

		u.save()
		u.userdata.save()

		if u.userdata.submitted == 0:
						
			log_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/log.txt')
			log_save_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/logs/test/') + u.username + test_no + ".txt"
			
			bot_manage  = path.join(mysite.settings.BASE_DIR,'/var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/')

			
			system('cp '+str(file_path1)+' /var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playerone/')
			system('cp '+str(file_path2)+' /var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playertwo/')     
			
	####################################################################################################################################

		
			rawinput = bot_path + "%" + "second.py"
			#chdir(bot_manage)
			p = Popen('sudo lxc-attach -n zango python /home/ubuntu/xodiaxyz/newbot.py',shell = True, stderr = PIPE, stdin = PIPE , stdout = PIPE)
			p.communicate(input = rawinput)[0]
			#print bot_path
			Popen('pwd',shell=True,stdout=PIPE)
			#print a.communicate
			system('cp /var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/log.txt '+path.join(mysite.settings.BASE_DIR,'xodiaxyz/'))
			f = open(log_path,'r')
			s1 = f.read()
			f.close()
			f = open(log_save_path,'w')
			f.write(s1)
			f.close()

		elif u.userdata.submitted == 1:
			log_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/log.txt')
			log_save_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/logs/test/') + u.username + "final.txt"
			
			bot_manage  = path.join(mysite.settings.BASE_DIR,'/var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/')

			
			system('cp '+str(file_path1)+' /var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playerone/')
			system('cp '+str(file_path2)+' /var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/playertwo/')     
			
	####################################################################################################################################

		
			rawinput = bot_path + "%" + "second.py"
			#chdir(bot_manage)
			p = Popen('sudo lxc-attach -n zango python /home/ubuntu/xodiaxyz/newbot.py',shell = True, stderr = PIPE, stdin = PIPE , stdout = PIPE)
			p.communicate(input = rawinput)[0]
			#print bot_path
			Popen('pwd',shell=True,stdout=PIPE)
			#print a.communicate
			system('cp /var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/log.txt '+path.join(mysite.settings.BASE_DIR,'xodiaxyz/'))
			f = open(log_path,'r')
			s1 = f.read()
			f.close()
			f = open(log_save_path,'w')
			f.write(s1)
			f.close()

		if u.userdata.test_no >= 2   :
			s = u.userdata.bot_path1 + "%" + u.userdata.bot_path2
			log_save_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/logs/test/') + u.username + "test1V2.txt"
			gentestlogfile(s,log_save_path)
		
		request.session['error'] = message				
		return HttpResponseRedirect(reverse('xodia:testpage'))

	else:
		return HttpResponse("You are not logged in")
	


def gentestlogfile(s,log_save_path):
	log_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/log.txt')
	bot_manage  = path.join(mysite.settings.BASE_DIR,'/var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/')
	#chdir(bot_manage)
	p = Popen('sudo lxc-attach -n zango python /home/ubuntu/xodiaxyz/newbot.py',shell = True, stderr = PIPE, stdin = PIPE , stdout = PIPE)
	p.communicate(input = s)[0]
	system('cp /var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/log.txt '+path.join(mysite.settings.BASE_DIR,'xodiaxyz/'))
	f = open(log_path,'r')
	s1 = f.read()
	f.close()
	f = open(log_save_path,'w')
	f.write(s1)
	f.close()
	
def genmatches(request):
	
	log_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/log.txt')
	for u1 in User.objects.all():
		if u1.userdata.submitted == 1:
			for u2 in User.objects.all():
				if (u2.userdata.submitted) == 1 and (u2.username != u1.username):
					s1 = u1.userdata.bot_pathf + "%" + u2.userdata.bot_pathf
					s2 = u2.userdata.bot_pathf + "%" + u1.userdata.bot_pathf
					log_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/log.txt')
					log_save_path1 = path.join(mysite.settings.BASE_DIR,'xodiaxyz/logs/final/') + u1.username + "V" + u2.username + ".txt" 
					log_save_path2 = path.join(mysite.settings.BASE_DIR,'xodiaxyz/logs/final/') + u2.username + "V" + u1.username + ".txt"
					p = Popen('sudo lxc-attach -n zango python /home/ubuntu/xodiaxyz/newbot.py',shell = True, stderr = PIPE, stdin = PIPE, stdout = PIPE)
					p.communicate(input = s1)[0]
					system('cp /var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/log.txt '+path.join(mysite.settings.BASE_DIR,'xodiaxyz/'))
					f = open(log_path,'r')
					log1 = f.read()
					f.close()
					f = open(log_save_path1,'w')
					f.write(log1)
					f.close()
					p = Popen('sudo lxc-attach -n zango python /home/ubuntu/xodiaxyz/newbot.py',shell = True, stderr = PIPE, stdin = PIPE, stdout = PIPE)
					p.communicate(input = s2)[0]
					system('cp /var/lib/lxc/zango/rootfs/home/ubuntu/xodiaxyz/log.txt '+path.join(mysite.settings.BASE_DIR,'xodiaxyz/'))
					f = open(log_path,'r')
					log2 = f.read()
					f.close()
					f = open(log_save_path2,'w')
					f.write(log2)
					f.close()
					if log1[-2] == 1 :
						u1.userdata.won+=1
						u1.userdata.points+=3
						u2.userdata.lost+=1
					
					elif log1[-2] == 2 :
						u2.userdata.won+=1
						u2.userdata.points+=3
						u1.userdata.lost+=1
					elif log1[-2] == 3 :
						u1.userdata.draw+=1
						u2.userdata.draw+=1
						u2.userdata.points+=1
						u1.userdata.points+=1

					if log2[-2] == 1 :
						u2.userdata.won+=1
						u2.userdata.points+=3
						u1.lost+=1
					elif log2[-2] == 2 :
						u1.userdata.won+=1
						u1.userdata.points+=3
						u2.userdata.lost+=1

					elif log2[-2] == 3 :
						u1.userdata.draw+=1
						u2.userdata.draw+=1
						u1.userdata.points+=1
						u2.userdata.points+=1

					u1.save()
					u1.userdata.save()
					u2.save()
					u2.userdata.save()
	return HttpResponse("The matches were generated")



   
@login_required(login_url = '/login/')
def gettestgame(request):
	u = request.user

	if "game" in request.POST:
		if request.POST['game'] == "game1" : 
			save_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/logs/test/')
			lfile = u.username + "test1.txt"
			file_path = path.join(save_path,lfile) 
			f = open(file_path,'r')
			log = f.read()
			f.close()
			return render(request,'xodia/ui.html',{'log':log,'user1':u.username,'user2':'Standard Bot'})
		elif request.POST['game'] == "game2":
			save_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/logs/test/')
			lfile = u.username + "test2.txt"
			file_path = path.join(save_path,lfile)
			f = open(file_path,'r')
			log = f.read()
			f.close()
			return render(request,'xodia/ui.html',{'log':log,'user1':u.username,'user2':'Standard Bot'})

		elif request.POST['game'] == "game3":
			save_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/logs/test/')
			lfile = u.username + "test1V2.txt"
			file_path = path.join(save_path,lfile)
			f = open(file_path,'r')
			log = f.read()
			f.close()
			return render(request,'xodia/ui.html',{'log':log,'user1':u.username + '1','user2':u.username + '2'})

		elif request.POST['game'] == "gamef":
			save_path = path.join(mysite.settings.BASE_DIR,'xodiaxyz/logs/test/')
			lfile = u.username + "final.txt"
			file_path = path.join(save_path,lfile)
			f = open(file_path,'r')
			log = f.read()
			f.close()
			return render(request,'xodia/ui.html',{'log':log,'user1':u.username ,'user2': 'Standard Bot'})


			

	else:
		return render(request,'xodia/uinogame.html',{'log':'' ,'user': u})









