package me.siddheshkothadi.chat

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.viewModels
import androidx.compose.foundation.isSystemInDarkTheme
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.Surface
import androidx.compose.runtime.SideEffect
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.core.splashscreen.SplashScreen.Companion.installSplashScreen
import androidx.core.view.WindowCompat
import com.google.accompanist.navigation.animation.AnimatedNavHost
import com.google.accompanist.navigation.animation.composable
import com.google.accompanist.navigation.animation.rememberAnimatedNavController
import com.google.accompanist.systemuicontroller.rememberSystemUiController
import dagger.hilt.android.AndroidEntryPoint
import me.siddheshkothadi.chat.ui.screens.*
import me.siddheshkothadi.chat.ui.theme.ChatTheme
import me.siddheshkothadi.chat.ui.viewmodel.MainViewModel

@AndroidEntryPoint
class MainActivity : ComponentActivity() {
    private val mainViewModel: MainViewModel by viewModels()

    @OptIn(
        ExperimentalMaterial3Api::class,
        androidx.compose.animation.ExperimentalAnimationApi::class
    )
    override fun onCreate(savedInstanceState: Bundle?) {
        WindowCompat.setDecorFitsSystemWindows(window, false)
        installSplashScreen()
        super.onCreate(savedInstanceState)

        setContent {
            val systemUiController = rememberSystemUiController()
            val useDarkIcons = !isSystemInDarkTheme()
            val navController = rememberAnimatedNavController()
            val isSignedIn by mainViewModel.isSignedIn.collectAsState()
            val users by mainViewModel.users.collectAsState(initial = emptyList())

            SideEffect {
                systemUiController.setSystemBarsColor(
                    color = Color.Transparent,
                    darkIcons = useDarkIcons,
                )
            }

            ChatTheme {
                Surface(
                    modifier = Modifier.fillMaxSize()
                ) {
                    AnimatedNavHost(
                        navController,
                        startDestination = if (isSignedIn) "chatList" else "login"
                    ) {
                        composable(
                            "login"
                        ) {
                            LoginScreen(mainViewModel)
                        }

                        composable(
                            "chatList"
                        ) {
                            ChatListScreen(navController, mainViewModel)
                        }

                        composable(
                            "myProfile"
                        ) {
                            MyProfile(navController, mainViewModel)
                        }

                        composable(
                            "profile/{uid}"
                        ) {
                            val uid =
                                navController.currentBackStackEntry?.arguments?.getString("uid")

                            if (uid != null) {
                                val user = users.first {
                                    it.uid == uid
                                }
                                ProfileScreen(navController, user)
                            }
                        }

                        composable(
                            "chat/{uid}"
                        ) {
                            val uid =
                                navController.currentBackStackEntry?.arguments?.getString("uid")

                            if (uid != null) {
                                val user = users.first {
                                    it.uid == uid
                                }
                                ChatScreen(
                                    navHostController = navController,
                                    mainViewModel = mainViewModel,
                                    user = user,
                                )
                            }
                        }
                    }
                }
            }
        }
    }
}