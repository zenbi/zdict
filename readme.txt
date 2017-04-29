zdict
-----

zdict is a simple lookup tool for English speakers learning Japanese.
Unlike other Japanese dictionaries, zdict uses romanji to ease the
translation process.

zdict uses the GTK+ toolkit (version 3)


edict
-----

This program uses the GPL version (pre 2000-03-25) of Jim Breen's edict
japanese-english dictionary.

You may not link a non-GPL version of edict into zdict.

More information about edict can be found in:

	edict.txt
	edict_r.txt
	edict_license.txt

and the edict homepage at http://www.csse.monash.edu.au/~jwb/j_edict.html

Note: the EDICT.DOC file (refered to in the edict license) was renamed
to edict.txt to prevent confusion with Word documents.


Webpage
-------

	http://zwin.org/zdict/


Install
-------

To compile, you need the GTK+ 3 development libs and a C compiler.

For debian based distributions:

apt-get install build-essential libgtk-3-dev libgdk-pixbuf2.0-dev pkg-config

Then:

1) make
2) make install

By default, the files will install into /usr.  To change the destination,
pass PREFIX to make:

make install PREFIX=/usr/local
