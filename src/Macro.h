//
//  Macro.h
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/22.
//

#define	SAFE_DELETE(x)		if(x){delete x; x = NULL;}
#define	SAFE_DELETE_ARRAY(x)	if(x){delete [] x; x = NULL;}
