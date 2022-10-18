import { createApi, fetchBaseQuery } from "@reduxjs/toolkit/query/react";

const crytoNewsHeaders = {
    'X-BingApis-SDK': 'true',
    'X-RapidAPI-Host': 'bing-news-search1.p.rapidapi.com',
    'X-RapidAPI-Key': '5f7713095amshe79b555179822a2p11d556jsnfb874a56c046'
};

const baseUrl = "https://bing-news-search1.p.rapidapi.com";

const createRequests = (url) => ({ url, headers: crytoNewsHeaders })

export const cryptoNewsApi = createApi({
    reducerPath: 'cryptoNewsApi',
    baseQuery: fetchBaseQuery({ baseUrl }),
    endpoints : ( builder) => ({
        getCryptoNews : builder.query({
            query: ({newsCategory, count}) => createRequests(`/news/search?q=${newsCategory}&safeSearch=Off&textFormat=Raw&freshness=Day&count=${count}`)
        })
    })
});

export const {
    useGetCryptoNewsQuery,
} = cryptoNewsApi;
