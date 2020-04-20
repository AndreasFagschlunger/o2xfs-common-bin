plugins {
    `cpp-library`
    `maven-publish`
    `visual-studio`
}

import org.gradle.language.cpp.internal.DefaultCppBinary

group = "at.o2xfs"
version = "1.0-SNAPSHOT"

library {
    linkage.set(listOf(Linkage.STATIC))
    targetMachines.set(listOf(machines.windows.x86, machines.windows.x86_64))
}

tasks.withType(CppCompile::class.java).configureEach {
    macros.put("_UNICODE", null)
    macros.put("UNICODE", null)

    val javaHome = System.getenv("JAVA_HOME") ?: System.getProperty("java.home")    
    includes.from(files("$javaHome/include", "$javaHome/include/win32"))
}

publishing {
    repositories {
        maven {
            url = if((version as String).endsWith("-SNAPSHOT")) uri("https://repo.fagschlunger.co.at/libs-snapshot-local") else uri("https://repo.fagschlunger.co.at/libs-release-local")
            credentials {
                val maven_username: String? by project
                val maven_password: String? by project
                username = maven_username
                password = maven_password
            }
        }
    }
}
