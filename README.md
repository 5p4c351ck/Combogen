Combogen
========

Combogen is a simple proof-of-concept password generator written in C.
It generates every possible combination of the keywords given.


Disclaimer
----------

This software is intended for legitimate and ethical purposes only.
Use this software responsibly and respect the privacy and security of others.


Building
-------

```
$ gcc main.c combogen.c -o combogen
```


Usage
-----

```
$ ./combogen -o outputfile keyword1 keyword2 ...
```

**Note**: With each keyword the possible combinations grow exponentially,
so keep it to a few keywords, otherwise the output file  will be huge.
