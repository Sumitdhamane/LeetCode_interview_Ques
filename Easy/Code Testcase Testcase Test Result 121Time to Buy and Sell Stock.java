class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = prices[0];
        int maxPrice = 0;
        
        for(int i = 0; i<prices.length; i++){
            int currentPrice = prices[i];
            if(currentPrice < minPrice){
                minPrice = currentPrice;
            }else{
                int profit = currentPrice - minPrice;
                if(profit > maxPrice){
                    maxPrice = profit;
                }
            }
        }
        return maxPrice;
    }
}
