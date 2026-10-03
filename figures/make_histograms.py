import matplotlib.pyplot as plt

DATA = {
    9: {4:2232,5:752,6:1068,7:3040,8:418,9:896,10:1080,12:372,16:768},
    10: {6:11736,7:4255,8:10379,9:18679,10:10428,11:16430,12:7250,13:6366,14:5364,15:2826,16:1877,17:9764,18:8564,24:16579,25:15634},
    11: {7:134379,8:34335,9:77453,10:173943,11:82265,12:159735,13:105222,14:66258,15:80232,16:41434,17:30688,18:68146,19:53452,24:61979,25:164588,26:93500,33:70599}
}
labels = {9:'$n=9$: four-edge seeds',10:'$n=10$: six-edge seeds',11:'$n=11$: seven-edge seeds'}
for n,d in DATA.items():
    xs=sorted(d)
    ys=[d[x] for x in xs]
    fig,ax=plt.subplots(figsize=(7.2,4.1))
    ax.bar(xs,ys,width=0.78)
    ax.set_xlabel(r'Closure size $|\operatorname{cl}_n(S)|$')
    ax.set_ylabel('Number of seeds')
    ax.set_title(labels[n])
    ax.set_xticks(xs)
    ax.ticklabel_format(axis='y',style='plain')
    ax.grid(axis='y',alpha=0.2)
    fig.tight_layout()
    fig.savefig(f'/mnt/data/final_package/figures/closure_hist_n{n}.pdf',bbox_inches='tight')
    fig.savefig(f'/mnt/data/final_package/figures/closure_hist_n{n}.png',dpi=220,bbox_inches='tight')
    plt.close(fig)
