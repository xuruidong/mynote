
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


## 同时管理多个key

### 环境：
* Windows
* MobaXterm

### 生成ssh key
`ssh  ssh-keygen -t ras -C "youremail@yourcompany.com"`
默认文件是 ~/.ssh/id_rsa, 需要生成多个key 时，指定不通的路径或文件名

### 添加私钥
`$ ssh-add ~/.ssh/id_rsa_xxx`
在MobaXterm 环境下需要执行 `$ sudo ssh-add ~/.ssh/id_rsa_xxx`

### 配置文件 
```bash
touch config
```

```
# gitlab
Host gitlab.com
    HostName gitlab.com
    PreferredAuthentications publickey
    IdentityFile ~/.ssh/id_rsa
# github
Host github.com
    HostName github.com
    PreferredAuthentications publickey
    IdentityFile ~/.ssh/id_rsa_github
```

### 将公钥添加到 github/gitlab

### 测试
```
ssh -T git@github.com
```


## Semantic Commit Messages
* build: Changes that affect the build system or external  dependencies (example scopes: gulp, broccoli, npm)
* chore: (updating grunt tasks etc; no production code change)
* ci: Changes to our CI configuration files and scripts (example scopes: Travis, Circle, BrowserStack, SauceLabs)
* docs: Documentation only changes
* feat: A new feature
* fix: A bug fix
* perf: A code change that improves performance
* refactor: A code change that neither fixes a bug nor adds a feature
* style: Changes that do not affect the meaning of the code (white-space, formatting, missing semi-colons, etc)
* test: Adding missing tests or correcting existing tests