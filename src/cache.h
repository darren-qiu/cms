#ifndef _CACNE_H
#define _CACHE_H

typedef struct post {
	post * pHead;
	post * pTail;
	uint64_t msgid;
} CMS_Post;

class CMS_Cache {
	CMS_Cache();
	~CMS_Cache();
public:
	CMS_Post* malloc_cache();
	int free_cache(CMS_Post& post);
private:
	int init(int cou);
	int extend(int cou);
	int clear();
private:
	CMS_Post * pHead;
	CMS_Post * pTail;
	CMS_Post * pFreeHead;
	CMS_Post * pFreeTail;
	int cou;
	int freecou;
}; // end CMS_Posting

#endif // _POSTING_H

