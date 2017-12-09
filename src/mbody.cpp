#include "mbody.h"

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

CMS_MBody::CMS_MBody(const CMS_MBody& body) {
    _msgid = body._msgid;
    _channel = body._channel;
    _type = body._type;
    _sdtime = body._sdtime;
    _content = body._content;
    _sdrid = body._sdrid;
    _sdrnick = body._sdrnick;
    _deadline = body._deadline;
    _level = body._level;
}

CMS_MBody& CMS_MBody::operator=(const CMS_MBody& body) {
	if(this != &body) {
		_msgid = body._msgid;
		_channel = body._channel;
		_type = body._type;
		_sdtime = body._sdtime;
		_content = body._content;
		_sdrid = body._sdrid;
		_sdrnick = body._sdrnick;
		_deadline = body._deadline;
		_level = body._level;
	}
	return *this;
}

uint64_t CMS_MBody::value() {
	return _msgid;
}

