#for further assistance see : http://dev.mysql.com/doc/connector-python/en/connector-python-examples.html
import mysql.connector
from mysql.connector import errorcode

try:
  cnx = mysql.connector.connect(host='localhost',
                                       database='employee',#database employee should already exist
                                       user='root',
                                       password='system')
  cursor = cnx.cursor()
except mysql.connector.Error as err:
  if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
    print("Something is wrong with your user name or password")
  elif err.errno == errorcode.ER_BAD_DB_ERROR:
    print("Database does not exist")
  else:
    print(err)

#The following three codes should be executed separately

#1.1 Executing a SQL command
try:
    cursor.execute("""CREATE TABLE employee_data
                   (id int primary key,name text)""")
except mysql.connector.Error as err:
        print(err.msg)
cursor.close()
cnx.close()

#1.2 Inserting Data into a table
add_employee="""INSERT INTO employee_data
VALUES(%s, %s)"""   #we use %s for all data types
data_employee=(12,'Sheldon Cooper') #data passed as tuple
try:
    cursor.execute(add_employee,data_employee)
except mysql.connector.Error as err:
        print(err.msg)
cursor.close()
cnx.close()

#1.3 Querying data
QUERY="""SELECT * FROM employee_data WHERE id BETWEEN %s AND %s"""
data_employee=(1,100)
try:
    cursor.execute(QUERY,data_employee)
except mysql.connector.Error as err:
        print(err.msg)

for(id,name) in cursor:
    print (id,name)
    
cursor.close()
cnx.close()
