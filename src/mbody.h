//
//  mbody.h
//  comm_msgsys
//
//  Created by 邱东洋 on 2017/11/30.
//  Copyright © 2017年 darren. All rights reserved.
//

#ifndef _MBODY_H
#define _MBODY_H

#include <string>

using namespace std;

class CMS_MBody;
typedef CMS_MBody* pMBody;

class CMS_MBody {
public:
    CMS_MBody():_msgid(0),
		_channel(0),
		_type(0),
		_sdtime(0),
		_content(""),
		_sdrid(""),
		_sdrnick(""),
		_deadline(0),
		_level(0) 
	{};
    CMS_MBody(uint64_t msgid,
              char channel,
              char type,
              uint64_t sdtime,
              string & content,
              string & sdrid,
              string & sdrnick,
              uint64_t deadline,
              char level);
    CMS_MBody(const CMS_MBody& body);
public:
    uint64_t _msgid;
    char _channel;
    char _type;
    uint64_t _sdtime;
    string _content;
    string _sdrid;
    string _sdrnick;
    uint64_t _deadline;
    char _level;
}; // end CMS_MBody

#endif /* _MBODY_H */
