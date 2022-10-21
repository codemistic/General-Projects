package me.siddheshkothadi.chat.di

import android.content.Context
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.android.qualifiers.ApplicationContext
import dagger.hilt.components.SingletonComponent
import me.siddheshkothadi.chat.ChatApplication
import me.siddheshkothadi.chat.data.repository.DataStoreRepositoryImpl
import me.siddheshkothadi.chat.data.repository.FirebaseRepositoryImpl
import me.siddheshkothadi.chat.data.repository.UserRepositoryImpl
import me.siddheshkothadi.chat.domain.repository.DataStoreRepository
import me.siddheshkothadi.chat.domain.repository.FirebaseRepository
import me.siddheshkothadi.chat.domain.repository.UserRepository
import javax.inject.Singleton

@Module
@InstallIn(SingletonComponent::class)
object AppModule {
    @Singleton
    @Provides
    fun provideApplication(@ApplicationContext context: Context): ChatApplication {
        return context as ChatApplication
    }

    @Singleton
    @Provides
    fun provideFirebaseRepository(context: ChatApplication): FirebaseRepository {
        return FirebaseRepositoryImpl(context)
    }

    @Singleton
    @Provides
    fun provideDataStoreRepository(context: ChatApplication): DataStoreRepository {
        return DataStoreRepositoryImpl(context)
    }

    @Singleton
    @Provides
    fun providesUserRepository(context: ChatApplication, firebaseRepository: FirebaseRepository, dataStoreRepository: DataStoreRepository): UserRepository {
        return UserRepositoryImpl(context, firebaseRepository, dataStoreRepository)
    }
}