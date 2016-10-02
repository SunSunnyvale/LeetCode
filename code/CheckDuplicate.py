import urllib2
import time

def find_between( s, first, last ):
    try:
        start = s.index( first ) + len( first )
        end = s.index( last, start )
        return s[start:end]
    except ValueError:
        return ""

some_url='https://na.ads.yahoo.com/yax/banner?ve=1&tt=1&si=146750051&megamodal=$\{MEGAMODAL\}&bucket=500&asz=300x250&u=https://www.yahoo.com/&gdAdId=DMJtfdgnOG8-&gdUuid=RdZVKDIwNi6NaTmyVuEEdRuEMjAwMVcOjfMRNXOs&gdSt=1460571635185178&publisher_blob=$\{RS\}|RdZVKDIwNi6NaTmyVuEEdRuEMjAwMVcOjfMRNXOs|2023538075|LREC4|1460571635.190005|2-9-9:ysd:2&pub_redirect=https://beap-bc.yahoo.com/yc/YnY9MS4wLjAmYnM9KDE3b2o3N2M1dChnaWQkUmRaVktESXdOaTZOYVRteVZ1RUVkUnVFTWpBd01WY09qZk1STlhPcyxzdCQxNDYwNTcxNjM1MTg1MTc4LHNpJDQ0NTIwNTEsc3AkMjAyMzUzODA3NSx0ZSQ4LGN0JDI1LHlieCRvRW53UFdlc3NsZzJtcnJLZ2Rackp3LGxuZyRlbi11cyxjciQ0NDkxNjQyNTUxLHYkMi4wLGFpZCRETUp0ZmRnbk9HOC0sYmkkMjI5NTQ2OTA1MSxtbWUkOTY3NDAyMzIxMTY2NjI5MDg1OCxyJDAseW9vJDEsYWdwJDM1MDU5NzEwNTEsYXAkTFJFQzQpKQ/2/*&K=1'

req = urllib2.Request(some_url)
req.add_header('Cookie', 'B=0ajpeqpbgt2dm&b=3&s=2e; ucs=lnct=1460570553; AO=u=1; AMCV_att1=MCAID%7C2B6C8CE305012379-40000138600049EC; DK=v=2&t=mb1&r=mb1; DSS=ts=1457740301&cnt=0&sdts=1454050661347&sdtp=crmas;')
req.add_header('User-Agent', 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.110 Safari/537.36')

count=0

for x in range(0, 1000):
	try:
		content1 = urllib2.urlopen(req).read()
		time.sleep(0.003)
		content2 = urllib2.urlopen(req).read()
	except:
		print "Unexpected error:", sys.exc_info()[0]
		continue
	output1=find_between(content1, "CrId:", ", RmxCrId:")
	output2=find_between(content2, "CrId:", ", RmxCrId:")
	
	if output1==output2:
		print output1, output2, True, x, count
		count=count+1
	else:
		print output1, output2, False, x, count

print count

	 




