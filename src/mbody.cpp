#include "mbody.h"

CMS_MBody::CMS_MBody() {
}

CMS_MBody::CMS_MBody(uint64_t msgid,
		char channel,
		char type,
		uint64_t sdtime,
		string & content,
		string & sdrid,
		string & sdrnick,
		uint64_t deadline,
		char level) {
    _msgid = msgid;
    _channel = channel;
    _type = type;
    _sdtime = sdtime;
    _content = content;
    _sdrid = sdrid;
    _sdrnick = sdrnick;
    _deadline = deadline;
    _level = level;
}

CMS_MBody::CMS_MBody(CMS_MBody& body) {
    _msgid = body.msgid;
    _channel = body.channel;
    _type = body.type;
    _sdtime = body.sdtime;
    _content = body.content;
    _sdrid = body.sdrid;
    _sdrnick = body.sdrnick;
    _deadline = body.deadline;
    _level = body.level;
}

