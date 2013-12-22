#! /bin/bash



#====================================================
#name   : check file's postfix
#input  : 
#output : 0:invalid,>0:valid
#globle : none
#decribe: 
#====================================================
function check_postfix
{
   if [ `echo $1 |grep '\.h$' |wc -l` -gt 0\
 -o `ls $1 |grep '\.c$' |wc -l` -gt 0\
 -o `ls $1 |grep '\.cpp$' |wc -l` -gt 0 ]
  then
#    echo $1
    return 1
  fi
  return 0
}

#====================================================
#name   : decode
#input  : file path
#output : none
#globle : none
#decribe: decode a file
#====================================================
function decode_file
{ 
  local postfix=".bak"
  local new_path=$1${postfix}
  cat $1 > $new_path
  rm -rf $1
  mv $new_path $1
}

#====================================================
#name   : find_file
#input  : directory path and file list
#output : none
#globle : none
#decribe: find file rather than directory
#====================================================
function decode_path
{
  local root=$1
  shift
  local file_in
  local path
  for file_in in $* 
  do
    path=${root}/${file_in}
    if [ -d $path ] ;then 
      decode_path $path `ls $path`
    else
      check_postfix $path
#      echo $?
      if [ $? -gt 0 ] ;then
	 decode_file $path
      fi
    fi    
  done
}

#====================================================
#decribe: main
#====================================================
if [ $# -lt 1 ] ;then
  echo "please enter a valid path for decode!"
else
echo sta `date`:
  if [ -d $1 ] ;then
    decode_path $1 `ls $1`
  else
    decode_file $1
  fi
#  echo "decode over!"
echo end  `date`:
fi
