/*
X-UIDL: 42d45d1f000007ca
X-Mozilla-Status: 0001
X-Mozilla-Status2: 00000000
Return-Path: <gvcormac@plg2.math.uwaterloo.ca>
Received: from plg2.math.uwaterloo.ca (plg2.math.uwaterloo.ca [129.97.186.80])
	by speedy.uwaterloo.ca (8.12.8/8.12.5) with ESMTP id j8E5H8oe015859
	for <catchall@speedy.uwaterloo.ca>; Wed, 14 Sep 2005 01:17:08 -0400
Received: (from gvcormac@localhost)
	by plg2.math.uwaterloo.ca (8.11.7/8.11.7) id j8E5H1U07267
	for catchall@speedy; Wed, 14 Sep 2005 01:17:01 -0400 (EDT)
Received: from demeter.uwaterloo.ca (cerberus.uwaterloo.ca [129.97.128.141])
	by plg2.math.uwaterloo.ca (8.11.7/8.11.7) with ESMTP id j8E5GvE07248
	for <gvcormac@plg.uwaterloo.ca>; Wed, 14 Sep 2005 01:16:57 -0400 (EDT)
Received: from sunkay.cs.ualberta.ca (sunkay.cs.ualberta.ca [129.128.4.11])
	by demeter.uwaterloo.ca (8.13.1/8.13.1) with ESMTP id j8E5Gna6000308
	for <gvcormac@uwaterloo.ca>; Wed, 14 Sep 2005 01:16:51 -0400
Received: from sedalia.cs.ualberta.ca ([129.128.4.36]:42762 "helo sedalia")
	by sunkay.cs.ualberta.ca with SMTP id S577156AbVINFQt (ORCPT
	<rfc822;gvcormac@uwaterloo.ca>); Tue, 13 Sep 2005 23:16:49 -0600
Date: Tue, 13 Sep 2005 23:16:49 -0600
From: Piotr Rudnicki <piotr@cs.ualberta.ca>
To: Gordon Cormack <gvcormac@uwaterloo.ca>
Subject: [broderic@cs.ualberta.ca: B]
Message-ID: <20050914051649.GA26519@sedalia.cs.ualberta.ca>
Mime-Version: 1.0
Content-Type: text/plain; charset=us-ascii
Content-Disposition: inline
User-Agent: Mutt/1.4.1i
X-Greylist: Recipient e-mail whitelisted, not delayed by milter-greylist-2.0 (demeter.uwaterloo.ca [192.168.128.178]); Wed, 14 Sep 2005 01:16:52 -0400 (EDT)
X-Miltered: at demeter with ID 4327B241.000 by Joe's j-chkmail (http://j-chkmail.ensmp.fr)!
X-Virus-Scanned: ClamAV version 0.86.2, clamav-milter version 0.86 on localhost
X-Virus-Status: Clean
X-Spam-Checker-Version: SpamAssassin 2.60-cvs (1.191-2003-06-06-exp)
X-Spam-Level: 
X-Spam-Status: No, hits=-4.9 required=5.0 tests=BAYES_00,RCVD_IN_OSIRU
	RCVD_IN_OSIRU_OR autolearn=ham version=2.60-cvs
Status: RO

Here is Broderick's B.

PR


----- Forwarded message from Broderick Arneson <broderic@cs.ualberta.ca> -----

Date:	Tue, 13 Sep 2005 19:13:06 -0600
From:	Broderick Arneson <broderic@cs.ualberta.ca>
To:	piotr@cs.ualberta.ca
Subject: B (oops)
User-Agent: Mutt/1.4.1i
X-Envelope-To: <"|/usr/tees1/cshome/piotr/Mail/RabidFire/filter /usr/tees1/cshome/piotr"> (uid 16220)
X-Orcpt: rfc822;piotr@cs.ualberta.ca
Original-Recipient: rfc822;piotr@cs.ualberta.ca

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int i,j,c,k,max,m,t,cross,bank,moved,p,big;
	int arr[2][10005], id[2][10005];
	int bn[2],cn[2];
	char str[65];
	int finished[10005];
	int first = 1;

	scanf("%d ", &c);
	while(c--) {
		scanf("%d %d %d ", &max,&cross,&m);
		if (!first) printf("\n");
		first = 0;

		t = 0;
		moved = 0;
		bank = 0;
		memset(bn, 0, sizeof(bn));
		memset(cn, 0, sizeof(cn));
		for (i=0; i<m; i++) {
			scanf("%d %s ", &j,str);
			k = 0;
			if (!strcmp("right", str)) k = 1;
			arr[k][bn[k]] = j;
			id[k][bn[k]++] = i;
			big = j;
		}
		while (moved < m) {
                        //printf("time %d bank %d\n",t,bank);
			// load any available cars on this bank
		        i = cn[bank];
			for (j=0; i < bn[bank] & j<max; i++,j++) {
				if (arr[bank][i] <= t) 
					finished[id[bank][i]] = t+cross;
				else break;
			}
			// we moved at least one car...
			if (j) {  
				cn[bank]+=j;
				moved+=j;
				t += cross;
				bank^=1;
				continue;
			}

			// no cars on this bank, is there one on the other bank?
			i = cn[bank^1];
			if (i < bn[bank^1] && arr[bank^1][i] <= t) {
				t += cross;
				bank ^= 1;
				continue;
			}

			// no cars; we wait until one arrives
			j = k = big;
			if (cn[bank] < bn[bank]) j = arr[bank][cn[bank]];
			if (cn[bank^1] < bn[bank^1]) k = arr[bank^1][cn[bank^1]];
			p = t;
			t = (j < k) ? j : k;
			//printf("%d: Waiting: (%d,%d) : until %d\n", p,j,k,t);
		}

		for (i=0; i<m; i++) printf("%d\n", finished[i]);
	}
	return 0;
}


