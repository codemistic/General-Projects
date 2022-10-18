import { configureStore } from "@reduxjs/toolkit";

import { cryptoApi } from "../services/cryproApi";
import { cryptoNewsApi } from "../services/cryptoNewsApi";

export default configureStore({
    reducer: {
        [cryptoApi.reducerPath]: cryptoApi.reducer,
        [cryptoNewsApi.reducerPath]: cryptoNewsApi.reducer,
    },
}); 