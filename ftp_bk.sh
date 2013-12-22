####本地的/home/databackup to ftp服务器上的/home/data####
#!/bin/bash

cur_date=`date +%y_%m%d_%H%M`

home_dir=/home/wuff/apps_proc/MiFi/sdk
bakfile_dir=$home_dir$cur_date

cp -rf $home_dir $bakfile_dir

#decode the code
cd /home/wuff/temp
./decode.sh $bakfile_dir

#package the directory
cd $bakfile_dir
htdocsname='sdk_'$cur_date'.zip'
zip -r $htdocsname $bakfile_dir >/dev/null

#ftp upload file
ftp -n<<!
open www.hojy.com
user lim limiao
binary
#hash
cd /wuff_dont_del/code_bak
lcd $bakfile_dir
prompt
put $htdocsname $htdocsname
close
bye
!

#remove the temp file
rm -rf $bakfile_dir
exit
