package me.siddheshkothadi.chat.ui.screens

import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.AccountCircle
import androidx.compose.material.icons.filled.ExitToApp
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.navigation.NavHostController
import me.siddheshkothadi.chat.ui.components.ChatCard
import me.siddheshkothadi.chat.ui.viewmodel.MainViewModel

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun ChatListScreen(
    navHostController: NavHostController,
    mainViewModel: MainViewModel
) {
    val isUserListLoading by mainViewModel.isUserListLoading.collectAsState(false)
    val listOfUsers by mainViewModel.users.collectAsState(emptyList())
    val isLoggingOut by mainViewModel.isLoggingOut.collectAsState()

    val openDialog = remember {
        mutableStateOf(false)
    }

    Scaffold(
        topBar = {
            Surface(tonalElevation = 2.dp) {
                CenterAlignedTopAppBar(
                    title = {
                        Text("Chat")
                    },
                    modifier = Modifier.windowInsetsPadding(
                        WindowInsets.statusBars.only(
                            WindowInsetsSides.Top
                        )
                    ),
                    actions = {
                        IconButton(onClick = {
                            openDialog.value = true
                        }) {
                            Icon(Icons.Default.ExitToApp, null)
                        }
                    },
                    navigationIcon = {
                        IconButton(onClick = {
                            navHostController.navigate("myProfile")
                        }) {
                            Icon(Icons.Default.AccountCircle, "Account")
                        }
                    }
                )
            }
        },
    ) {
        if (openDialog.value) {
            AlertDialog(
                onDismissRequest = { openDialog.value = false },
                confirmButton = {
                    TextButton(
                        onClick = {
                            mainViewModel.signOut()
                        },
                        enabled = !isLoggingOut
                    ) {
                        Text("Yes")
                    }
                },
                dismissButton = {
                    TextButton(onClick = { openDialog.value = false }) {
                        Text("Cancel")
                    }
                },
                title = {
                    Text("Log out?")
                },
                text = {
                    Text("All chats and account information linked with this account will be permanently deleted.")
                },
                icon = {
                    Icon(Icons.Default.ExitToApp, null)
                }
            )
        }
        LazyColumn(
            contentPadding = PaddingValues(vertical = 8.dp)
        ) {
            items(listOfUsers) {
                ChatCard(
                    user = it,
                    onClickAction = {
                        navHostController.navigate("chat/${it.uid}")
                    },
                    navigateToProfile = {
                        navHostController.navigate("profile/${it.uid}")
                    }
                )
            }
            if (isUserListLoading) {
                item {
                    Row(
                        modifier = Modifier
                            .fillMaxWidth()
                            .padding(vertical = 24.dp),
                        horizontalArrangement = Arrangement.Center
                    ) {
                        CircularProgressIndicator(
                            Modifier
                                .width(24.dp)
                                .height(24.dp)
                        )
                    }
                }
            }
        }
    }
}