#include "o2xfs-common.h"

namespace o2xfs {

	LPVOID ToPointer(JNIEnv *env, jbyteArray array) {
		LPVOID result = NULL;
		if (array != NULL) {
			env->GetByteArrayRegion(array, 0, sizeof(LPVOID), (jbyte*) &result);
		}
		return result;
	}

	jbyteArray ToArray(JNIEnv* env, LPVOID lpData) {
		jbyteArray result = env->NewByteArray(sizeof(lpData));
		env->SetByteArrayRegion(result, 0, sizeof(LPVOID), (jbyte*) &lpData);
		return result;
	}
}