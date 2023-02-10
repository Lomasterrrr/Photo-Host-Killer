# PhotoHostKiller C++ 0.0.1-beta
![alt text](https://i.imgur.com/vA1Iy0D.png)

## $ Linux 
```
$ git clone https://github.com/Lomasterrrr/Photo-Host-Killer
$ cd Photo-Host-Killer
$ make
$ cd bin
$ ./parser
$ all
```
## $ Using
```

  PhotoHostKiller - by lomaster | OldTeam

    usage:
      ./parser [options]     run parser

    options:
      -D, --domain           set domain
      -F, --format           set format
      -P, --path             set path
      -G, --generate         set method
      -GC, --generatecount   set generate lenght

      -C, --count            set count

    optional arguments:
      -h, --help            show this help message

```

## $ FastRun
### imgur
``` bash
./parser -D i.imgur.com -F .png -P out/ -G 1 -GC 5 -C 100
```
### lightshot
``` bash
./parser -D prnt.sc -F .png -P out/ -G 1 -GC 5 -C 100
```
### freeimage
``` bash
./parser -D iili.io -F .png -P out/ -G 1 -GC 7 -C 100
```
### pasteboard
``` bash
./parser -D gcdnb.pbrd.co/images -F .png -P out/ -G 1 -GC 12 -C 100
```
