
[git官方教程](https://git-scm.com/book/zh/v2)  

config 的三个作用域  
* --local (缺省)， 只对某个仓库有效  
* --gloabl 对当前用户所有仓库有效  
* --system 对系统所有登录用户有效  

显示config 的配置 
git config --list --local


git add -u  添加所有被跟踪且发生变更的文件  
变更文件名 git mv a b  
清空暂存区 git reset

查看提交日志  git log --oneline  
git log -n 4  查看最近4条  
git log -n 4 bugfix 查看bugfix 分支 
git log --oneline --all 查看所有分支  
git log --oneline --all --graph 图形方式查看  

图形界面查看工具 gitk
