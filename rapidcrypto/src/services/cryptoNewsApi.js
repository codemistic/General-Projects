import { createApi, fetchBaseQuery } from "@reduxjs/toolkit/query/react";
const cryptoNewsApiHeaders = {
  "X-BingApis-SDK": "true",
  "X-RapidAPI-Key": "ec7850d461msh6dab9f5476e2fdap1b7da0jsn60cd0919e75b",
  "X-RapidAPI-Host": "bing-news-search1.p.rapidapi.com",
};
const baseUrl = "https://bing-news-search1.p.rapidapi.com";

const createRequest = (url) => ({ url, headers: cryptoNewsApiHeaders });

export const cryptoNewsApi = createApi({
  reducerPath: "cryptoNewsApi",
  baseQuery: fetchBaseQuery({ baseUrl }),
  endpoints: (builder) => ({
    getCryptoNews: builder.query({
      query: ({ newsCategory, count }) =>
        createRequest(
          `/news/search?q=${newsCategory}&safeSearch=Off&textFormat=Raw&freshness=Day&count=${count}`
        ),
    }),
  }),
});

export const { useGetCryptoNewsQuery } = cryptoNewsApi;
