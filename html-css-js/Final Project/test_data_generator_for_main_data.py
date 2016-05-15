import random
import string
import json
import sys
lst_dates=[{'date': '1-May-07'}, {'date': '2-May-07'}, {'date': '3-May-07'}, {'date': '4-May-07'}, {'date': '7-May-07'}, {'date': '8-May-07'}, {'date': '9-May-07'},
     {'date': '10-May-07'}, {'date': '11-May-07'}, {'date': '14-May-07'}, {'date': '15-May-07'}, {'date': '16-May-07'}, {'date': '17-May-07'},
     {'date': '18-May-07'}, {'date': '21-May-07'}, {'date': '22-May-07'}, {'date': '23-May-07'}, {'date': '24-May-07'}, {'date': '25-May-07'},
     {'date': '29-May-07'}, {'date': '30-May-07'}, {'date': '31-May-07'}, {'date': '1-Jun-07'}, {'date': '4-Jun-07'}, {'date': '5-Jun-07'},
     {'date': '6-Jun-07'}, {'date': '7-Jun-07'}, {'date': '8-Jun-07'}, {'date': '11-Jun-07'}, {'date': '12-Jun-07'}, {'date': '13-Jun-07'},
     {'date': '14-Jun-07'}, {'date': '15-Jun-07'}, {'date': '18-Jun-07'}, {'date': '19-Jun-07'}, {'date': '20-Jun-07'}, {'date': '21-Jun-07'},
     {'date': '22-Jun-07'}, {'date': '25-Jun-07'}, {'date': '26-Jun-07'}, {'date': '27-Jun-07'}, {'date': '28-Jun-07'}, {'date': '30-Jun-07'}]

lst_data=lst=[{"country":"India","state":"jk","district":"doda","block":"101","panchayat":"A","village":"a","population":123,"literacy_rate":0.75},
    {"country":"India","state":"jk","district":"doda","block":"101","panchayat":"B","village":"b","population":126,"literacy_rate":0.89},
     {"country":"India","state":"punjab","district":"sangrur","block":"132","panchayat":"C","village":"c","population":1236,"literacy_rate":0.809},
     {"country":"India","state":"up","district":"agra","block":"1332","panchayat":"D","village":"d","population":1226,"literacy_rate":0.489},
     {"country":"India","state":"mp","district":"sagar","block":"123","panchayat":"E","village":"e","population":12263,"literacy_rate":0.689},
     {"country":"India","state":"uk","district":"dehradun","block":"13","panchayat":"F","village":"f","population":1236,"literacy_rate":0.789},
     {"country":"India","state":"hp","district":"shimla","block":"11","panchayat":"G","village":"g","population":1236,"literacy_rate":0.819}]
lst=[]

for i in range(0,100):
    temp={}
    temp["state"]=''.join(random.choice(string.ascii_uppercase ) for _ in range(5))
    temp["district"]=''.join(random.choice(string.ascii_lowercase ) for _ in range(5))
    temp["block"]=''.join(random.choice(string.digits) for _ in range(5))
    temp["panchayat"]=''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(5))
    temp["village"]=''.join(random.choice(string.ascii_lowercase + string.digits) for _ in range(5))
    for j in lst_dates:
        temp2=temp
        temp2["date"]=j["date"]
        temp2["population"]=random.randint(100,1000)
        temp2["literacy_rate"]=(random.randint(10,100)/100.000000000)*100
        lst.append(temp2.copy())

#Outputting data to json file 
out = sys.stdout
sys.stdout = open('main_data.json', 'w')
print json.dumps(lst)
sys.stdout = out
