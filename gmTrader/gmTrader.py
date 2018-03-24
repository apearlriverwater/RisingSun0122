# -*- coding: utf-8 -*-

from gmsdk.api import StrategyBase

class Mystrategy(StrategyBase):
    def __init__(self, *args, **kwargs):
        super(Mystrategy, self).__init__(*args, **kwargs)


    def on_error(self, code, msg):
        print ("error ",code ,msg)
        pass

    def on_bar(self, bar):
        #print(bar.strendtime,bar.sec_id,bar.close)
        pass

    def on_execrpt(self, res):
        pass

    def on_order_status(self, order):
        pass

    def on_order_new(self, res):
        pass

    def on_order_filled(self, res):
        pass

    def on_order_partiall_filled(self, res):
        pass

    def on_order_stop_executed(self, res):
        pass

    def on_order_canceled(self, res):
        pass

    def on_order_cancel_rejected(self, res):
        pass


if __name__ == '__main__':
    myStrategy = Mystrategy(
        username='haigezyj@qq.com',
        password='zyj2590@1109',
        strategy_id='cd401156-0aef-11e8-a857-dc5360304926',
        #subscribe_symbols='SZSE.000651.bar.60',
        mode=4  #回测模式
    )
    myStrategy.backtest_config(
        start_time='2018-02-02 09:05:00',
        end_time='2018-02-09 16:00:00',
        initial_cash=100000,
        transaction_ratio=0.95,
        commission_ratio=0,
        slippage_ratio=0,
        price_type=1)

    #ret = myStrategy.run()
    #print('exit code: ', ret)

    #资金流信息分析、计算