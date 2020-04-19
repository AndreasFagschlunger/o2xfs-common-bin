#ifndef O2XFS_COMMON_BIN
#define O2XFS_COMMON_BIN

#include <Windows.h>
#include <jni.h>

namespace o2xfs {
	
	LPVOID ToPointer(JNIEnv* env, jbyteArray array);

	jbyteArray ToArray(JNIEnv* env, LPVOID lpData);

}

#endif
