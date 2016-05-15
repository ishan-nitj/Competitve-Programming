import json
import sys
with open("main_data.json") as json_file:
    json_data = json.load(json_file)
lst=json_data
population1={}#state wise
population2={}#distric wise
population3={}#block wise
literacy_rate1={}#state wise
literacy_rate2={}#distric wise
literacy_rate3={}#block wise
lst1=[]
lst2=[]
lst3=[]
for i in lst:
    state_name=i["state"]
    district_name=i["district"]
    block_name=i["block"]
    panchayat_name=i["panchayat"]
    village_name=i["village"]
    date=i["date"]
    
    if population1.get((state_name,date),"none")=="none":
        population1[state_name,date]=0
        population1[state_name,date]+=i["population"]
        literacy_rate1[state_name,date]=0
        literacy_rate1[state_name,date]+=(i["literacy_rate"]*i["population"])
    else:
        population1[state_name,date]+=i["population"]
        literacy_rate1[state_name,date]+=(i["literacy_rate"]*i["population"])

    if population2.get((district_name,date),"none")=="none":
        population2[district_name,date]=0
        population2[district_name,date]+=i["population"]
        literacy_rate2[district_name,date]=0
        literacy_rate2[district_name,date]+=(i["literacy_rate"]*i["population"])
    else:
        population2[district_name,date]+=i["population"]
        literacy_rate2[district_name,date]+=(i["literacy_rate"]*i["population"])

    if population3.get((block_name,date),"none")=="none":
        population3[block_name,date]=0
        population3[block_name,date]+=i["population"]
        literacy_rate3[block_name,date]=0
        literacy_rate3[block_name,date]+=(i["literacy_rate"]*i["population"])
    else:
        population3[block_name,date]+=i["population"]
        literacy_rate3[block_name,date]+=(i["literacy_rate"]*i["population"])

for i in literacy_rate1:
    literacy_rate1[i]/=population1[i]
    
for i in literacy_rate2:
    literacy_rate2[i]/=population2[i]
    
for i in literacy_rate3:
    literacy_rate3[i]/=population3[i]

for key in population1:
    temp={}
    temp["state"]=key[0]
    temp["date"]=key[1]
    temp["population"]=population1[key]
    temp["literacy_rate"]=literacy_rate1[key]
    lst1.append(temp.copy())

for key in population2:
    temp={}
    temp["district"]=key[0]
    temp["date"]=key[1]
    temp["population"]=population2[key]
    temp["literacy_rate"]=literacy_rate2[key]
    lst2.append(temp.copy())

for key in population3:
    temp={}
    temp["block"]=key[0]
    temp["date"]=key[1]
    temp["population"]=population3[key]
    temp["literacy_rate"]=literacy_rate3[key]
    lst3.append(temp.copy())

#Outputting data to different files
out = sys.stdout
sys.stdout = open('state.json', 'w')
print json.dumps(lst1)
sys.stdout = out

out = sys.stdout
sys.stdout = open('district.json', 'w')
print json.dumps(lst2)
sys.stdout = out

out = sys.stdout
sys.stdout = open('block.json', 'w')
print json.dumps(lst3)
sys.stdout = out
