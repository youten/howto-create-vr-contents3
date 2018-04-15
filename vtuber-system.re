#@# VRコンテンツのつくりかた3 技術書典4
#@# （）かっこは全角統一する。
#@# ユーザ入力は""ダブルクォーテーション、メニュー表示文字列は「」かぎかっこにでくくる。

= バーチャルYouTuberとそのシステム

//image[aichannel-01][キズナアイのYouTubeチャンネル A.I.Channel][scale=0.70]

== バーチャルYouTuberとは

バーチャルYouTuberとは、バーチャル（仮想的な、事実上の）YouTuberのことで、VTuberなどと略されます。
火付け役であり、"親分"と称されるYouTubeチャンネル登録数トップの「キズナアイ@<fn>{vtuber-kizunaai}」さんが自称したのが用語としての始まりと言えますが、明確な定義があるわけではなく、またその形態は様々であるため、実際にリアルの人間ではない仮装アバターを用いていればおおむね全てバーチャルYouTuberと呼ばれているのが現状です。

キズナアイさんの最初のYouTube動画投稿は2016/11/29ですが、界隈としては2011/06/13に「First Vlog. Trying this out.」というタイトルでロンドンからのビデオメールを投稿した、Ami Yamatoさんなどが始祖の一人と認識されています。

また、YouTubeをメインターゲットとしない「にじさんじ@<fn>{nijisanji}」の方々は「バーチャルライバー」、SHOWROOMでの生放送がメインの「うたっておんぷっコ♪ 東雲めぐ@<fn>{showroom-sinonomemegu}」さんは「バーチャルSHOWROOMER」と名乗られています。

//footnote[vtuber-kizunaai][キズナアイのYoutubeチャンネル A.I.Channel　@<href>{https://www.youtube.com/channel/UC4YaOt1yT-ZeyB0OmxHgolA}]
//footnote[vtuber-amiyamato][Ami Yamato - First Vlog. Trying this out. @<href>{https://www.youtube.com/watch?v=5pciLZ8ffPY}]
//footnote[nijisanji][にじさんじ 公式バーチャルライバー @<href>{https://www.ichikara.co.jp/official}]
//footnote[showroom-sinonomemegu][はぴふり! 東雲めぐちゃんのお部屋♪@<href>{https://www.showroom-live.com/megu}]

== バーチャルYouTuberを実現するシステムの方式

バーチャルYouTuberを実現するシステムは主な構成要素として、アバターシステムと、そのキャラクターアバターをどのように動かすかというモーションキャプチャシステムの二つから成り立ちます。

システムの方式についてはアバターを2D/3Dどちらで実現するかという点で大きく2つに分かれ、その後、いわゆる中の人のモーションをどのようにキャプチャするか、あるいは擬似的に生成するか、その方式によって区分することができます。
このアバターシステムとモーションキャプチャシステム以外の企画や脚本、音声収録（ボイスチェンジャーを含む）や動画編集については通常のYouTuberと変わりがありませんので、重要な要素ではあるのですが本章では取り扱いません。

== アバターシステム

=== 2Dアバターシステム

==== Live2D

//image[live2d-cubism][Live2D Cubism][scale=0.70]

「Live2D@<fn>{live2d} Cubism」は、Live2D社の2Dイラスト絵のパーツ毎に動きの情報を指定することでアニメーションさせることができる技術です。

ソシャゲに多く採用されていますが、個人的に「バンドリ！ガールズバンドパーティ！@<fn>{bang-dream-girls-band-party}」のLive2D事例が随一だと思っています。
CGWORLDのCraft Eggインタビュー@<fn>{cgworld-craft-egg}が技術的なポイントを掴みやすく面白いのでぜひ一読を。

//footnote[live2d][Live2D @<href>{http://www.live2d.com/ja/}]
//footnote[bang-dream-girls-band-party][バンドリ！ガールズバンドパーティ！ @<href>{https://bang-dream.bushimo.jp/}]
//footnote[cgworld-craft-egg][『バンドリ！　ガールズバンドパーティ！』の登場キャラを魅力的にした、Live2Dによるモーション制作 | 特集 | CGWORLD.jp @<href>{https://cgworld.jp/feature/201709-cgw230HS-bang.html}]

==== Live2D EuclidとE-moteとその他

デファクトスタンダードとして知名度のあるLive2Dですが、一番メジャーである、その2Dイラスト絵を平面上で立体的に動かす技術は正式には「Live2D Cubism」といいます。
「Live2D Cubism」とは別にボディは3D、顔はアニメ技法的な投影を駆使して3D動作を実現する「Live2D Euclid@<fn>{live2d-euclid}」という技術・製品が別にあります。

その様子は（おそらく唯一の）Live2D Euclidを利用したVTuberである「ふぇありす@<fn>{fairys-channel}」さんや、Live2D Euclidのサンプルキャラクターである風花ちゃん（青髪の子）を利用することができるiPhoneX向けアプリの「パペ文字@<fn>{papemoji}」などにて確認することができます。

//footnote[live2d-euclid][Euclid | Live2D @<href>{http://www.live2d.com/ja/products/euclid}]
//footnote[fairys-channel][Fairys Channel - YouTube @<href>{https://www.youtube.com/channel/UC2Rr7mILebYLTjd38DNNUTw}]
//footnote[papemoji][パペ文字 | 株式会社 ViRD @<href>{http://vird.co.jp/product/puppemoji/}]

また、混同されやすいのですがLive2Dとは別に、同様の2Dキャラクターアニメーションツールとして、エムツー社の「E-mote@<fn>{mtwo-emote}」という技術・製品があり、VRにも対応した「E-mote VR」というバリエーションがあります。
筆者が「E-mote VR」をVR結婚式で体験した@<fn>{vr-wedding}感想としては、ビルボード感があるものの、元ゲームの2DとVR空間としての3Dが同一技術のため再現度という観点では不思議な没入感がありました。

新規HTML5プラットフォームで注目のシャニマスこと「アイドルマスター シャイニーカラーズ@<fn>{idolmaster-shinycolors}」の2Dアバターシステムは独自実装とのことで、キャラクターゲームのビッグタイトル用途から個人VTuberまでLive2D一強の現状が、変わっていくこともあるのか注目どころです。

//footnote[mtwo-emote][E-moteについて | キャラクターアニメーションツールE-mote @<href>{http://emote.mtwo.co.jp/about/}]
//footnote[vr-wedding][リアル式場でゲームキャラとVRで結婚、誓いのキスも 「新妻LOVELY×CATION VR結婚式 」レポート – PANORA @<href>{http://panora.tokyo/32636/}]
//footnote[idolmaster-shinycolors][アイドルマスター シャイニーカラーズ(シャニマス) | バンダイナムコエンターテインメント @<href>{https://idolmaster-shinycolors.bxd.co.jp/}]

=== 3Dアバターシステム

==== Unity, UnrealEngine（ゲームエンジン）

「Unity, UnrealEngine（ゲームエンジン）」という表現が適切ではないとは思いますが、現状、モーションキャプチャや映像・カメラ制御との連携、あるいは外部と通信の上、3Dキャラクターを統括的に扱うことができるプラットフォームとして、ゲームエンジンであるUnityが3Dアバターシステムの主流となっています。
同等の機能を持つゲームエンジンであるUnreal Engineでももちろん可能ですし、拡張性が限定されるものの、「3Dキャラクターを扱えるレンダリング・動画出力プラットフォーム」として、MayaやBlenderを使うこともできます。

ただし、「元々（Unreal Engineと比較して）個人デベロッパー向けに広まっている下地がある」「それを下地に、Ouclus RiftやHTC ViveなどのVR HMDの初心者向けの情報が多い」「VRChatのアバター・ワールドのSDKがUnity（5.6.3p1）限定であり、それを前提とした初心者向け情報が現在進行形で増えている」という要素から、未経験者が自由度の高いプラットフォームに手をつけてみたい際には、特にUnityがオススメと言えます。

==== MikuMikuDance + MikuMikuCapture, Hitogata, FaceVTuber

VTuberのメインの最終ターゲットは動画なので、3DCGムービー製作プラットフォームであるMikuMikuDance（略称：MMD）はノウハウドキュメントを含めた既存資産が多く、有力なプラットフォームの一つです。

2017年末時点では、全身の姿勢を取得することができるセンサデバイスであるKinectを用いた「MikuMikuCapture@<fn>{mikumikucapture}」がほぼ唯一の選択肢でしたが、Kinectはすでに生産終了してしまっているという欠点があります。

そんな中、MMD関連システムと言える流れで、2018年に入ってWebCamベースの「Hitogata@<fn>{hitogata}」と「FaceVTuber@<fn>{facevtuber}」が出てきました。

//image[hitogatabeta21][Hitogata beta2.1][scale=0.70]

「Hitogata」はMikuMikuMoving作者のMogg氏によるアバターシステムで、キャラメイク機能が含まれており、単体で素材となる動画を出力できるシステムです。
また、vmdエクスポート機能があり、「フェイス周りのモーションのみHitogataで生成したものを組み込んでMMD動画をつくる」という使い方もできます。

//image[facevtuber][FaceVTuber][scale=0.70]

「FaceVTuber」はブラウザで完結して独自のモデルの読み込みに対応し、動画の録画と保存を実施することができるアプリです。
インターフェイスからはわかりづらいですがライブラリを読み込む以外はローカルで動作し、モデル等のアップロードは行いません。
Three.jsのMMDLoader等の機能を用いていると思われます。

//footnote[mikumikucapture][MikuMikuCapture @<href>{https://sites.google.com/site/mikumikucapture/}]
//footnote[hitogata][Hitogata @<href>{https://sites.google.com/site/vhitogata/}]
//footnote[facevtuber][FaceVTuber @<href>{https://facevtuber.com/}]

==== パペ文字, ホロライブ

//image[papemoji-hololive][パペ文字（左）とホロライブ（右）][scale=0.80]

カメラ画像から顔の部位検出については、最近は機械学習でまた新たなフェーズを迎えてはいますが、昔から存在する定番の技術です。
TrueDepthカメラの機能を利用したアプリをインストールしたiPhoneXを貸し出している運用であるにじさんじ組に引き続き、カメラ画像からの入力でアバターシステムを実現するスマホアプリがこの4月頭、立て続けに2本、リリースされました。

「パペ文字@<fn>{vird-papemoji}」はViRD社のiPhoneX向けアバターシステムで、プリインの3Dキャラクター、Live2D Euclidのキャラクター、マスク画像などを切り替えて使うことができます。
パペ文字はその他のモデルの個別対応の相談をリリース時から受け付けているあたりが気になるポイントです。

また、「ホロライブ@<fn>{cover-hololive}」は「ときのそら@<fn>{tokinosora}」さんの運営元であるカバー社製のアバターシステムで、既存のARキャラクターアプリをリニューアルする形でリリースされました。
ホロライブはiPhoneX・iPhoneX以外のiPhone・Androidとプラットフォーム・ハードウェア特性にあわせて部位のトラッキング方式が違うことが特徴です。

元々、@GOROmanさんがFaceRig + Live2Dで実現した@<fn>{goroman-facerig}時点から明らかではあるのですが、本質的には顔の向きとそれっぽい表情の切り替えができればアバターシステムとしての要件は満たしていると言えます。
スマホアプリでライブ配信プラットフォームごとトータルサポートされたアプリが登場するのもそれほど遠くない未来だと思われます。

//footnote[vird-papemoji][パペ文字 | 株式会社 ViRD @<href>{http://vird.co.jp/product/puppemoji/}]
//footnote[cover-hololive][「ホロライブ」をApp Storeで @<href>{https://itunes.apple.com/jp/app/id1288450594}]
//footnote[tokinosora][SoraCh. ときのそらチャンネル - YouTube @<href>{https://www.youtube.com/channel/UCp6993wxpyDPHUpavwDFqgg}]
//footnote[goroman-facerig][中の人(二次元)になる方法【FaceRig × Live2D × Unity × OBS × AVVoiceChanger × 気合】 - Medium @<href>{https://medium.com/@GOROman_1661/%E4%B8%AD%E3%81%AE%E4%BA%BA-%E4%BA%8C%E6%AC%A1%E5%85%83-%E3%81%AB%E3%81%AA%E3%82%8B%E6%96%B9%E6%B3%95-facerig-live2d-unity-obs-avvoicechanger-%E6%B0%97%E5%90%88-d49c3d456ed6}]

==== バーチャルキャスト

録画や配信は画面キャプチャによる別アプリに頼ることができるため、PC向けのVRヘッドセットを使った単体アバターシステムが配布されだすだろうと思っていました。
そして、（後述する）AniCastがSHOWROOMと連携しているように、配信プラットフォームとの連携が進んでいくと考えていました。

//image[virtualcast-01][バーチャルキャスト][scale=0.7]

ところが、一足飛びなことにここへ来て「あいえるチャンネル@<fn>{il-channel}」を有するインフィニットループと、遊び要素たっぷりの「バーチャルのじゃロリ狐娘YouTuberおじさんことねこます@<fn>{nojaoji}」さんやにじさんじの「月ノ美兎@<fn>{tsukinomito}」さんのニコ生を実施しているドワンゴという強力タッグによる@<fn>{aori}、VRライブ・コミュニケーションサービス「バーチャルキャスト@<fn>{virtualcast}」がβリリースされました。

バーチャルキャストはVRキャラクターになりきってインターネット越しに音声を含むコミュニケーションが取れるシステムです。

「みゅみゅ@<fn>{miyumiyu}」さんがニコ生でやっていたVR空間システムがベースになっているとのことですが、色々機能がてんこ盛りな上にオリジナル3Dモデルのインポートにもすぐに対応予定とのことで（超会議のタイミングですかね？）、今後が楽しみなサービスです。

//image[virtualcast-02][Trackerの追加で逆立ちも可能][scale=0.7]

少しマニアックな観点ですごいなと思ったところを挙げておきます。

 * 絶妙な広角めのカメラ一体型ミラーが標準配備。他アイテム同様配置を変更できるのであおりも俯瞰も自在ですぐに面白い画を作って試せます。
 * 見栄えもするダイナミックでわかりやすいUI。一人称向けの手元空中コンソールではなくて、外側からもメニュー表示が見えます。
 * ファーストリリースでニコ生コメント連携も対応、他の人のルームに参加する「凸」の対応とその手軽さ。きちんと凸許可設定と他の凸可能な人のリストがあってすぐ凸できるIFがきっちり揃っていてうまいなと思いました。
 * Tracker追加によるトラッキングポイントの増加に対応、キャリブレーション時に自動で認識、最大でTrackerを7つ追加して両肘・両膝・両足・腰の10点トラッキング対応（@<img>{virtualcast-02}）。VRChatのいわゆる「フルトラッキング」勢がまさかの他サービスでも使えるようになるなんて、Tracker品薄が続くこと間違いなしの衝撃です。

//footnote[il-channel][あいえるちゃんねる/株式会社インフィニットループ - YouTube @<href>{https://www.youtube.com/channel/UC_IfjiHP6UnWE0NNog_n_3A}]
//footnote[nojaoji][けもみみおーこく国営放送 - YouTube @<href>{https://www.youtube.com/channel/UCt8tmsv8kL9Nc1sxvCo9j4Q}]
//footnote[tsukinomito][月ノ美兎 - YouTube @<href>{https://www.youtube.com/channel/UCD-miitqNY3nyukJ4Fnf4_A}]
//footnote[virtualcast][バーチャルキャスト[Virtual Cast\] @<href>{https://virtualcast.jp/}]
//footnote[aori][みゅみゅさん×MIROさんだし、やりたいことの1割とか言ってたし、いくら煽っても予想超えてくるやろ…]
//footnote[miyumiyu][✿。*みゅみゅちゃんねる♡*。✿-ニコニコミュニティ @<href>{https://com.nicovideo.jp/community/co1774343}]

== モーションキャプチャシステム

モーションキャプチャシステムについては、身体の部位をトラッキングするものから、顔をトラッキングするもの、あるいは音声入力から唇の形を推測するリップシンクなどが含まれます。
単体でなく、複数のシステムを組み合わせて利用するケースもあります。
また、「キャプチャ」とは言っていますが、擬似的に生成をしたり、手動で操作したり、編集フェーズで調整することも組み合わされます。

=== ボディトラッキング

==== HTC Vive + Tracker

VRヘッドセットシステムである「HTC Vive」を用いる方法です。

VRヘッドセットシステムはVR HMDの頭部と、コントローラの両手の空間座標をキャプチャすることができ、ここからキャラクターの姿勢を推定することができます。

//image[htc-vive-tracker][HTC Viveでの頭（HMD）・両手（コントローラ）・腰・両足（Tracker）の6点トラッキング][scale=0.85]

また、HTC Viveは「Tracker」という、HMDとコントローラ以外にもトラッキングポイントを追加することができるデバイスが標準で提供されており、主には頭（HMD）・両手（コントローラ）に加え腰・両足などを追加し、Trackerでトラッキングすることにより全身のキャプチャが可能となります。

IKinema社のOrion@<fn>{ikinema-orion}は6〜8箇所のTrackerを含めたViveトラッキングシステムから全身のキャプチャをするシステムで、100FPSオーダのリアルタイムキャプチャの他、fbxへのエクスポートもサポートしています。

//footnote[htc-vive][VIVE™ 日本 | 想像を超えたバーチャルリアリティの体験 @<href>{https://www.vive.com/jp/}]
//footnote[htc-vive-tracker][VIVE™ | VIVE Tracker @<href>{https://www.vive.com/jp/vive-tracker/}]
//footnote[ikinema-orion][IKinema | Motion Capture, VR, Games - Project Orion @<href>{https://ikinema.com/orion}]

==== IKによる姿勢の推定

VRヘッドセットシステムにより、各トラッキングポイントの座標と向きが取得できますが、そこから骨格をIK（Inverse Kinematicsの略、逆運動学）で求めることにより、姿勢を推定することができます。

こちらには、定評のあるIKライブラリである、「Final IK@<fn>{final-ik}」を組み合わせるのが3D Vtuberシステムの一つの定番です。
筆者も情報の多かったFinal IKベースでVTuberシステムを試してみました@<fn>{redo-how-to-vtuber}が、$90の有料でアセットであり、少々そのノウハウや成果物のOSS化には一手間が必要であり、運用ノウハウは少々閉じて蓄積されている印象です。

また、Unity標準のIK機能@<fn>{unity-ik}もあり、本書の後半ではこちらとXR APIを用いてVTuberシステムを構築した事例をとりあげます。

//footnote[final-ik][Final IK - Asset Store  @<href>{https://assetstore.unity.com/packages/tools/animation/final-ik-14290?aid=1011lGbg}]
//footnote[redo-how-to-vtuber][バーチャルYouTuberのやり方 #VTuber - ReDo @<href>{http://greety.sakura.ne.jp/redo/2018/01/how-to-vtuber.html}]
//footnote[unity-ik][Unity - マニュアル: IK @<href>{https://docs.unity3d.com/jp/530/Manual/InverseKinematics.html}]

==== Oculus Rift

VRヘッドセットシステムである「Oculus Rift」を用いる方法です。

//image[oculus-rift][Oculus Riftでの頭（HMD）・両手（コントローラ）3点トラッキング][scale=0.70]

HTC Viveと比較して「Trackerのような追加トラッキングユニットによる全身トラッキングには対応していない」というディスアドバンテージがありますが、逆にいうと全身トラッキングが不要であるケースでは「価格面で20,000円ほどベースセットが安い」「Viveの棒状のコントローラと比較して、Oculus Touchの方が手の形を直感的に表現できる」という観点でOculus Riftの方が優れています。

前述した東雲めぐさんはXVI社の「AniCast@<fn>{xvi-anicast}」を用いていますが、こちらはOculus Riftベースのシステムです。

個人的にはHTC Viveと比較して「軽量」「ヘッドホンシステムが標準装備で取り回しがしやすい」ことと、「Rift Core 2.0（β）による高パフォーマンスのデスクトップキャプチャが標準で使える」という利点があり、HTC Viveのルームスケールを活かせる広い部屋がない際など、ViveよりRiftがVTuberシステムのベースに向いてるケースもそれなりにあると思っています。

//footnote[oculus-rift][Oculus Rift - Oculus  @<href>{https://www.oculus.com/rift/}]
//footnote[xvi-anicast][XVI Inc. | バーチャルキャラクター配信システム「AniCast」プレスリリース @<href>{http://www.xvi.co.jp/news/anicast/}]
//footnote[rift-core-2-beta][Welcome to Rift Core 2.0—Beta Now Available | Oculus @<href>{https://www.oculus.com/blog/welcome-to-rift-core-beta-now-available/}]

==== Perception Neuron

モーションキャプチャシステムの「Perception Neuron@<fn>{perception-neuron}」を用いる方法です。

//image[perception-neuron][Perception Neuron][scale=0.80]

この手のモーションキャプチャシステムとしては非常に安価（約21万円）というのが特徴で、これと光学式カメラによるフェイシャルキャプチャを組み合わせた仕組みが大手（？）VTuberでは主流の方式となっています。

公表されてる範囲では、Perception Neuronベースのキャラクターシステムとして先駆者であるKiLA@<fn>{kila}が「虹川ラキ@<fn>{nijikawa-laki}」さんなどで採用されている他、「電脳少女シロYouTuber シロ@<fn>{siro-channel}」さんや「ばあちゃる@<fn>{bayoutuber}」さんは運用元であるアップランド株式会社の勉強会の「バーチャル美少女ねむ@<fn>{nemchan-nel}」さんによるレポート@<fn>{appland-vtuber-meetup}にて、Perception Neuronを使用していることがわかります。

//footnote[perception-neuron][Perception Neuron by Noitom | Perception Neuron motion capture for virtual reality, animation, sports, gaming and film @<href>{https://neuronmocap.com/ja}]
//footnote[kila][Kigurumi Live Animator [KiLA\] @<href>{https://kila.amebaownd.com/}]
//footnote[nijikawa-laki][Laki Station ラキステーション - YouTube @<href>{https://www.youtube.com/channel/UCp77Qho-YHhnklRr-DkjiOw}]
//footnote[siro-channel][Siro Channel - YouTube @<href>{https://www.youtube.com/channel/UCLhUvJ_wO9hOvv_yYENu4fQ}]
//footnote[bayoutuber][【世界初?!】男性バーチャルYouTuber ばあちゃる - YouTube @<href>{ https://www.youtube.com/channel/UC6TyfKcsrPwBsBnx2QobVLQ}]
//footnote[nemchan-nel][ねむちゃんねる【バーチャル美少女YouTuber】 - YouTube @<href>{https://www.youtube.com/channel/UC7xyzq_Hd72-IbJVoz4DSrQ}]
//footnote[appland-vtuber-meetup][バーチャルYouTuberだけど、シロちゃんの秘密を探りに「第１回バーチャル YouTuber 勉強会」に行ってきた！|バーチャル美少女ねむの人類美少女計画 @<href>{https://www.nemchan.com/2018/01/VtuberWorkshop.html}]

==== その他のモーションキャプチャシステム

その他、大規模から小規模まで、ビジネス用途の製品から、研究目的のシステムまで、さまざまなモーションキャプチャが使われています。

設備が大きく少し高額ですが光学式マーカーシステムの自由度が高く、複数人数での利用にも強いOptiTrack@<fn>{optitrack}、生産終了とはなってしまいましたがXBOXプラットフォームでのゲームへの利用・応用事例の豊富な@<fn>{kinect}、Kinectのデバイス・エコシステムの後継として期待されているRealSense@<fn>{realsense}が実際にVTuberに使われているのを確認できます。

また、現時点の雄であるOpenPose@<fn>{openpose}はライセンスの観点で研究目的の先の応用事例であるVTuberに適用しづらいのですが、機械学習ベースの画像認識ライブラリの進化が進んでおり、キャラクター設定によってはトラッキングの精度の低さが許容できる際など、「WebCamひとつあればいい」という世界はそれなりに広がっていくと考えられます。

//footnote[optitrack][OptiTrack Japan, Ltd.｜オプティトラック・ジャパン株式会社 @<href>{https://www.optitrack.co.jp/>]
//footnote[kinect][Kinect - Windows アプリの開発 @<href>{https://developer.microsoft.com/ja-jp/windows/kinect}]
//footnote[realsense][Intel® RealSense Technology | Intel® Software @<href>{https://software.intel.com/realsense}]
//footnote[openpose][CMU-Perceptual-Computing-Lab/openpose: OpenPose: Real-time multi-person keypoint detection library for body, face, and hands estimation @<href>{https://github.com/CMU-Perceptual-Computing-Lab/openpose}]

=== フェイストラッキング

フェイストラッキングは現状、主にカメラによる「画像認識からの顔の部位検出」とマイクによる「キャプチャ音声からの口の形を推測するリップシンク」の2種類の技術が主流で、これらの両方を組み合わせたりされています。

ただし、表情のトラッキングはせずにスクリプトで自動まばたきを行ったり、親しみやすい漫画・アニメ的表現である「＞＜顔」や「ジト目」や、汗の漫符など、モーフを手動で切り替えてしまう方法も多くのVTuberが採用しています。

カメラ画像による部位検出について、VR HMDを装着してしまっている際には目の位置などはもちろん検出できなくなってしまうのですが、Tobii社の視線追跡技術をHTC Viveに組み込んだもの@<fn>{tobii-eyetracking-vr}がある他、モバイル向けにもQualcomm社のSnapdragon 845ベースの次世代スタンドアローンVRヘッドセット開発キット@<fn>{qualcomm-snapdragon845-hmd-dev-kit}にも同Tobii社の視線追跡技術が組み込まれています。

現世代のVR HMDにアイトラッキングが標準搭載されてはいませんが、その高解像度化・高FPS化していく進化「視線が向いている部分だけ高解像度化する」というFoveated Renderingが高パフォーマンスのためには必要と考えられており、その際にアイトラッキングの機構が必須となります。

人間の目は微細眼球運動と呼ばれる、無意識下で視線が揺れる運動を行うことがわかっていますが、これがゆえに視線は入力ポインタとしては扱うことが難しいことがわかっています。
ただし、人間らしさの再現としてトラッキングできた眼球運動そのものをキャラクターに反映させることができると、よりリアリティの高い「生きた目」を実現することができるでしょう。

//footnote[tobii-eyetracking-vr][Tobii Pro offers VR integration services @<href>{https://www.tobiipro.com/ja/product-listing/vr-integration/}]
//footnote[qualcomm-snapdragon845-hmd-dev-kit][Qualcomm Announces Support for Next-Generation VR Experiences With New Snapdragon 845 Virtual Reality Development Kit | Qualcomm  @<href>{https://www.qualcomm.com/news/releases/2018/03/21/qualcomm-announces-support-next-generation-vr-experiences-new-snapdragon}]
