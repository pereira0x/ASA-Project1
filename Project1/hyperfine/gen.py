for j in range(0,50):
  df=open(str(j) + '.in', 'w')
  df.write(str(j) + "\n")
  df.write(str(j)+ "\n")
  for i in range(1,j+1):
    df.write(str(i)+ "\n")
  df.close()