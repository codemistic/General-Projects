import { createApi, fetchBaseQuery } from "@reduxjs/toolkit/query/react";

const crytoApiHeaders = {
    'X-RapidAPI-Host': 'coinranking1.p.rapidapi.com',
    'X-RapidAPI-Key': '5f7713095amshe79b555179822a2p11d556jsnfb874a56c046',
};

const baseUrl = 'https://coinranking1.p.rapidapi.com';

const createRequests = (url) => ({ url, headers: crytoApiHeaders })

export const cryptoApi = createApi({
    reducerPath: 'cryptoApi',
    baseQuery: fetchBaseQuery({ baseUrl }),
    endpoints : ( builder) => ({
        getCryptos : builder.query({
            query: (count) => createRequests(`/coins?limit=${count}`)
        }),

        getCryptoDetails: builder.query({
            query: (coinId) => createRequests(`/coin/${coinId}`),
        }),

        getCryptoHistory: builder.query({
            query: ({ coinId, timePeriod }) => createRequests(`coin/${coinId}/history?timeperiod=${timePeriod}`),
        }),
    })
});

export const {
    useGetCryptosQuery,
    useGetCryptoDetailsQuery,
    useGetCryptoHistoryQuery,
} = cryptoApi;
