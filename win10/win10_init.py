import winreg

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
        print ("disable %s"%(service) )
        key = winreg.OpenKeyEx(winreg.HKEY_LOCAL_MACHINE, 
                               r'SYSTEM\CurrentControlSet\Services\%s'%(service),
                               access=winreg.KEY_SET_VALUE)
    
        winreg.SetValueEx(key, 'Start', 0, winreg.REG_DWORD, 4)
        winreg.CloseKey(key)
        
    
def folder_set():
    dic = {
    '{0ddd015d-b06c-45d5-8c4c-f59713854639}':'Local Pictures',
    '{35286a68-3c57-41a1-bbb1-0eae73d76c95}':'Local Videos',
    '{a0c69a99-21c8-4671-8703-7934162fcf1d}':'Local Music',
    '{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}':'Desktop'
    
    }
    
    for entry in dic:
        key = winreg.OpenKeyEx(winreg.HKEY_LOCAL_MACHINE, 
                               r'SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\FolderDescriptions\%s\PropertyBag'%(entry),
                               access=winreg.KEY_SET_VALUE) 
        
        winreg.SetValueEx(key, 'ThisPCPolicy', 0, winreg.REG_SZ, 'Hide')
        winreg.CloseKey(key)        

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
    
    
if __name__ == '__main__':
    show_reg_app()
    svr_list = ['AppXSvc']
    disableService(svr_list)
    print ("****************")
