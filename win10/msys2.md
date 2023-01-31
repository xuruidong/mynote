
# MSYS2


```
$ pacman -S zsh
warning: database file for 'ucrt64' does not exist (use '-Sy' to download)
warning: database file for 'clang32' does not exist (use '-Sy' to download)
warning: database file for 'clang64' does not exist (use '-Sy' to download)
error: failed to prepare transaction (could not find database)
```

```
pacman -Sy
```

```
error: zsh: signature from "David Macek <david.macek.0@gmail.com>" is unknown trust
:: File /var/cache/pacman/pkg/zsh-5.8-5-x86_64.pkg.tar.zst is corrupted (invalid or corrupted package (PGP signature)).
Do you want to delete it? [Y/n] Y
error: failed to commit transaction (invalid or corrupted package (PGP signature))
Errors occurred, no packages were upgraded.
```
```
# pacman -Sy msys2-keyring
# pacman -Syu
```
[参考](https://bbs.archlinux.org/viewtopic.php?id=258247)  


## 更新MSYS2
```
pacman -Syyuu
```
[https://skfwe.cn/p/msys2-signature-is-marginal-trust/](https://skfwe.cn/p/msys2-signature-is-marginal-trust/)  

## 查看MSYS2 版本？
```
# pacman -Ss filesystem
```
