import winreg
import ctypes, sys

# 'HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\xboxgip'
services_list = [
    'xboxgip', 'XblAuthManager', 'XboxGipSvc', 'XboxNetApiSvc', 'XblGameSave',
    'edgeupdate', 'edgeupdatem',
    'PhoneSvc',
    'PimIndexMaintenanceSvc_463de',
    'WalletService',
    'WMPNetworkSvc',
    'AppXSvc'
]

def show_reg():
    key = winreg.OpenKeyEx(winreg.HKEY_LOCAL_MACHINE, r'SYSTEM\CurrentControlSet\Services\xboxgip')
    print(dir(key.handle))
    # print
    i = 0
    while True:
        try:
            name, value, type1 = winreg.EnumValue(key,i)
            print (name, value)
            i += 1
        except WindowsError as e:
            print (e)
            break
    winreg.CloseKey(key)

'''
Diagnostic Policy Service
Diagnostic Service Host
Diagnostic System Host
Connected User Experiences and Telemetry
Touch Keyboard and Handwriting Panel Service  # IME
'''
def disableService(services_list):
    for service in services_list:
        try:
            print ("disable %s"%(service) )
            key = winreg.OpenKeyEx(winreg.HKEY_LOCAL_MACHINE, 
                                   r'SYSTEM\CurrentControlSet\Services\%s'%(service),
                                   access=winreg.KEY_SET_VALUE)
        
            winreg.SetValueEx(key, 'Start', 0, winreg.REG_DWORD, 4)
            winreg.CloseKey(key)
        except Exception as e:
            print("disable %s error %s"%(service, e))
        
    
def folder_set():
    dic = {
    '{0ddd015d-b06c-45d5-8c4c-f59713854639}':'Local Pictures',
    '{35286a68-3c57-41a1-bbb1-0eae73d76c95}':'Local Videos',
    '{a0c69a99-21c8-4671-8703-7934162fcf1d}':'Local Music',
    '{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}':'Desktop'
    
    }
    
    for entry in dic:
        try:
            key = winreg.OpenKeyEx(winreg.HKEY_LOCAL_MACHINE, 
                                   r'SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\FolderDescriptions\%s\PropertyBag'%(entry),
                                   access=winreg.KEY_SET_VALUE) 
            
            winreg.SetValueEx(key, 'ThisPCPolicy', 0, winreg.REG_SZ, 'Hide')
            winreg.CloseKey(key)  
        except Exception as e:
            print ("hide %s error, %s"%(dic[entry], e))
    
    namespace_dict = {
        # '{088e3905-0323-4b02-9826-5d99428e115f}': 'Download',
        '{0DB7E03F-FC29-4DC6-9020-FF41B59E513A}':  '3D objects',
        '{24ad3ad4-a569-4530-98e1-ab02f9417aa8}': "Pictures",
        '{3dfdf296-dbec-4fb4-81d1-6a3438bcf4de}': 'Music',
        '{d3162b92-9365-467a-956b-92703aca08af}': "documents",
        '{f86fa3ab-70d2-4fc7-9c99-fcbf05467f3a}': "Videos"
        # '{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}': 'Desktop',
    }
    for entry in dic:
        try:
            winreg.DeleteKeyEx(winreg.HKEY_LOCAL_MACHINE, 
                                r'SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\MyComputer\NameSpace\%s'%(entry),
                                )  
        except Exception as e:
            print ("hide %s error, %s"%(dic[entry], e))    


def show_reg_app():
    # LockApp.exe
    key = winreg.OpenKeyEx(winreg.HKEY_LOCAL_MACHINE, r'SOFTWARE\Microsoft\Windows\CurrentVersion\Authentication\LogonUI\SessionData')
    print(dir(key.handle))
    # print
    i = 0
    while True:
        try:
            name, value, type1 = winreg.EnumValue(key,i)
            print (name, value)
            i += 1
        except WindowsError as e:
            print (e)
            break
    winreg.CloseKey(key)
    
def show_env_path():
    key = winreg.OpenKeyEx(winreg.HKEY_CURRENT_USER, r'Environment',
                           access=winreg.KEY_READ)
    print(dir(key.handle))  # 'HKEY_CURRENT_USER\Environment'
    # print
    i = 0
    
    res = winreg.QueryValueEx(key, "Path")
    print (res)
    print ("======")
    
    while True:
        try:
            name, value, type1 = winreg.EnumValue(key,i)
            print (name, value)
            i += 1
        except WindowsError as e:
            print (e)
            break
    winreg.CloseKey(key)

    
def is_admin():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False

def get_admin_privileges():
    if sys.version_info[0] == 3:
        ctypes.windll.shell32.ShellExecuteW(None, "runas", sys.executable, __file__, None, 1)
    else:#in python2.x
        ctypes.windll.shell32.ShellExecuteW(None, u"runas", unicode(sys.executable), unicode(__file__), None, 1)

import time
import os
import getpass

if __name__ == '__main__':
    if (not is_admin()):
        get_admin_privileges()
    
    # show_reg_app()
    # svr_list = ['AppXSvc']
    disableService(services_list)
    folder_set()
    
    print (getpass.getuser())
    print (is_admin())
    print ("pid= %s"%(os.getpid()))
    # time.sleep(5)
    # show_env_path()

    print ("****************")
    time.sleep(5)
    print ("+="*20)
