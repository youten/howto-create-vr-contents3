#@# VRコンテンツのつくりかた3 技術書典4
#@# （）かっこは全角統一する。
#@# ユーザ入力は""ダブルクォーテーション、メニュー表示文字列は「」かぎかっこにでくくる。

= UnityとHTC Viveで3DアバターVTuberシステムをつくってみる

さて、バーチャルYouTuberシステムの技術要素について理解できましたら、次は実際につくってみましょう。

この章では、Unityを用いて、VRヘッドセットシステムであるHTC Viveをベースとした3DアバターのVTuberシステムを作ってみた話について、要素をひとつひとつ説明します。

== 基本方針

前章のとおり、バーチャルYouTuberシステムはその実現方式は多様です。
本書で扱うバーチャルYouTuberシステムはそのやり方を主に2つの方針に沿って決めました。

1つは、「VR技術を使った3Dアバターシステムである」ことです。
こちらは筆者がVR技術が好きで、トラッキングポイントが増やせたり、HMDの代わりに頭に装着することもできるTrackerが好きで、3Dキャラクターを扱うシステムと仲良くするのが好きだからです。

もう1つは、本書などを参考に「やってみようと思った人が成功しやすいように、シンプルで、一通りの情報がまとまっている」ことです。

//image[redo-how-to-vtuber][ReDo（筆者Blog） - バーチャルYouTuberのやり方 #VTuber][scale=0.70]

本書の前身とも言えるのですが、2017年度にVive Trackerの登場からゆるゆると流行した、「VRコスプレ」の先駆者達の情報をかけあわせて、Unity+Vive+Final IK式のシステムを組んでみて、その成果を筆者のBlogエントリ@<fn>{redo-how-to-vtuber}にまとめました。

これを参考にVTuberシステムを作ってみようと思うと、複数の情報を「いい感じに」繋げる必要があり、UnityとVR開発経験がない人は正直脱落してしまっているんじゃないかな、と思いました。
他人様のライブラリにおんぶにだっこではあるのですが、そのあたりをどうにかできるものを目指してみました。

//footnote[redo-how-to-vtuber][バーチャルYouTuberのやり方 #VTuber - ReDo @<href>{http://greety.sakura.ne.jp/redo/2018/01/how-to-vtuber.html}]

=== 完成品とOSSリポジトリ

本章で説明するバーチャルYouTuberシステムは、YVTuber（Yume VTuber System）@<fn>{github-yvtuber}という名前でOSSとしてGitHubに公開しています。

特徴としてはAsset Store配布のアセットを一切含んでおらず、ファイル一式をダウンロードしてUnityで開くと、すぐ実行することができます。

また、このリポジトリには改造・再配布に制限のあるものを一切含んでおりません。
詳細は各アセットフォルダ配下のreadmeやLICENSEファイルを参照願います。

実際のところ、デファクトスタンダードであるFinal IK（VR IK）や、Steam VR SDKを素直に使った方が長い運用を考えるとお得だとは思うのですが、多彩な「俺の考えた最強のバーチャルYouTuberシステム」がどんどん出てきてみんなで使い分けたり、OSSであれば自由に改造しあったりして、楽しめたらいいなと考えています。

//footnote[github-yvtuber][YVTuber @<href>{https://github.com/youten/YVTuber}]

=== XR Mecanim IK Plus

YVTuberは@chobi_luckさんのXR Mecanim IK Plus@<fn>{xr-mecanimikplus}をベースにしています。
こちらは実のところ、XR Mecanim IK Plusは、ユニティちゃんモデルのアセットを追加することで、十分にバーチャルYouTuberシステムとして成り立つ完成品です。
これをベースに、ライセンス上自由度の高いモデル（後述します）を組み込み、全てのアセットをリポジトリに含む、別途一切のダウンロード・追加が必要ないものに組み立てました。

//footnote[xr-mecanimikplus][XR Mecanim IK Plus @<href>{http://chobi-glass.com/Unity/XR_MecanimIKPlus.html}]

=== Unity XR APIベースであるメリット

XR Mecanim IK Plusをベースにした副産物なのですが、Unity XR APIをベースにしているためSteam VRプラグインが不要であり、Oculus Rift環境でも一応動作します@<fn>{yvtuber-oculus}。
Steam VR側がOculus RiftやWinMRに対応している互換性については把握していたのですが、Unity標準機能として徐々に整備されてきており、これはこれで十分だなと感じました。
後述しますがTrackerにも対応しており、目立って非対応の機能というとバイブレーションぐらいとのことです。

//footnote[yvtuber-oculus][コントローラの形状が物理的に違うため、使いづらい機能があります]

== 3Dモデルの調達について

3DベースのVTuberシステムでは必須となる3Dモデルですが、その調達については悩みどころです。
この節では、その3Dモデルの調達方式についての見解と、筆者が今回どうしたかということについて述べます。

=== 発注しよう…としたけど仕様が決められない

餅は餅屋、最初に考えるのが誰かにお願いすることなのですが、1体数十万から数百万と言われる3Dモデルを発注しようと考えた際に、すぐに「仕様が決められない」ことに気づきます。
一般的なソフトウェアの世界に照らし合わせると、「発注範囲（工程）」と「機能要件」と「品質」について、どのような選択肢があるのかをわかっていないといけません。
まずは実際に使ってみたり、作ってみたりして勉強が必要だな、と考えました。

=== 完成品のモデルを利用する

そんなわけで発注するにも勉強が必要なことが分かってしまいましたが、次に完成品のモデルを利用することを考えます。
いくつかの具体例を挙げます。

==== Unity Asset Storeで販売されているモデルを利用する

UnityのAsset Storeで販売されているアセットは、無料・有料を問わず原則「改変可」「ロイヤリティ不要で商用利用可能」「実行形式に組み込んで容易に取り出せる形でなければ再配布可」と、あくまでUnity上で動作させる際には特別な制限がありません@<fn>{asset-store-howto-point}。

//image[suriyun][Unity Asseto Store - SURIYUN][scale=0.70]

「カフェ野ゾンビ子@<fn>{cafe-no-zombi-ko}」さんはSURIYUNさんの「Zombie Girl01@<fn>{zombie-girl01}」を、「雨下カイト@<fn>{amashita-kite}」さんはGAME ASSET STUDIOさんの「Taichi Character Pack@<fn>{taichi}」を使われている模様です。

//footnote[asset-store-howto-point][アセットストアが選ばれる5つの特徴 @<href>{http://assetstore.info/howto/howto-point/}]
//footnote[store-suriyun][SURIYUN - Asset Store @<href>{https://assetstore.unity.com/publishers/10786}]
//footnote[cafe-no-zombi-ko][Zombi-Ko Channel - YouTube @<href>{https://www.youtube.com/channel/UCiVRnULJjc8o-j_lG5BAzKw}]
//footnote[zombie-girl01][Zombie Girl01 - Asset Store @<href>{https://assetstore.unity.com/packages/3d/characters/humanoids/zombie-girl01-97923}]
//footnote[amashita-kite][Kite Channel - YouTube @<href>{https://www.youtube.com/c/KiteChannelOfficial}]
//footnote[taichi][Taichi Character Pack - Asset Store @<href>{https://assetstore.unity.com/packages/3d/characters/taichi-character-pack-15667}]

==== インターネットで配布されているモデルを利用する

「みゅみゅ@<fn>{myumyu}」さんが「ニコニ立体ちゃんことアリシア・ソリッド@<fn>{alicia}」を使っている事例が一番有名だと思いますが、おなじみ「ユニティちゃん@<fn>{unity-chan-web}」や「中野シスターズ@<fn>{nakasis}」など、いくつかライセンスの自由度が高いモデルが無償で配布されています。

配布モデルそれぞれに利用規約がありますので、よく確認の上、遵守しましょう。

改変可能なモデルのテクスチャ色だけを変更するなどの手法は、識別性が良く難易度も低いので便利です。

//footnote[myumyu][みゅ みゅ - YouTube @<href>{https://www.youtube.com/channel/UC_tFMq_yvulj-yzQDqmH9SQ}]
//footnote[alicia][ニコニ立体ちゃん特設サイト - ニコニ立体 @<href>{http://3d.nicovideo.jp/alicia/}]
//footnote[nakasis][中野シスターズ（ナカシス） 公式サイト @<href>{http://nakasis.com/}]
//footnote[unity-chan-web][UNITY-CHAN! OFFICIAL WEBSITE @<href>{http://unity-chan.com/}]

=== 筆者の悪あがき事例紹介

結局のところ、モデラーさんが作られたモデルを使うのが正道なのですが、もう少し他の方法も探ってみました。

==== Blenderでの自作

自然な人型タイプではなく、各パーツが円柱や球でシンプルで、宙に浮いており、ロボットや不定形のキャラクターなら少々形が壊れても問題ないのでは、と考えました。
筆者はジョイメカファイトが大好きです。

//image[droid-on-unity][ドロイド君ことAndroid Robot][scale=0.60]

ちなみに、このドロイド君@<fn>{youten-android-robot}をつくるのには、Blenderの本をみながら20時間ぐらい勉強した後、6時間ほどかかりました。
1回undoできない間違った操作をしてしまい、ゼロからやりなおしました@<fn>{youten-blender}。

//footnote[youten-android-robot][youten/android-robot: Android Robot a.k.a. Droid-kun 3d model by blender @<href>{https://github.com/youten/android-robot}]
//footnote[youten-blender][やっていきBlender 第1回 週休七日ドロイド君をつくるまで - ReDo @<href>{http://greety.sakura.ne.jp/redo/2018/01/blender-1.html}]

==== PMCAでの生成

実際にドロイド君を使ってみた感想として、「もう少し身長と高い頭身が欲しい」「手と指が欲しい」「モーフが欲しい」ということに気づきました。

//image[pmca][PMCA（PMD Mob Character Assembler）v0.0.6r10][scale=0.70]

そこで、MMDモデル組み立てソフトであるPMCA（PMD Mob Character Assembler）@<fn>{pmca}を利用しました。
このソフトはいわゆる「モブ子さん」を生成するツールなのですが、大胆なことにツールがまるっとPublic Domainライセンスと宣言されており、デフォルトで同梱されているパーツを使う限りにおいては、本ツールで生成されたモデルにも同ライセンスが適用されます。

これで生成したpmdを、Blenderにて、mmd_tools@<fn>{blender-plugin-mmd-tools}プラグインでfbxに変換したものを使っています。

//footnote[pmca][PMCA（PMD Mob Character Assembler）v0.0.6 @<href>{http://matosus304.blog106.fc2.com/blog-entry-215.html}]
//footnote[blender-plugin-mmd-tools][@<href>{https://github.com/powroupi/blender_mmd_tools}]
//footnote[blender-plugin-cats][@<href>{https://github.com/michaeldegroot/cats-blender-plugin}]

== 機能の実装（基本編）

それでは、Unity上で機能の実装を行なっていきましょう。

=== はじめに完成品の動作確認

前述のYVTuberのリポジトリから、プロジェクト一式をダウンロードして、Unityで開いてください。
筆者は2017.3.1p4で動作確認をしています。

「Assets」内、「YVTuber」＞「Basic」シーンを開きます。
SteamVRが起動しており、コントローラ2つも認識されていることを確認した上で、「Play」を実行します。
正常に起動していれば、キャラクターの手や体がコントローラに追従することが、正面のミラーで確認できると思います（@<img>{yvtuber-basic-01}）。

//image[yvtuber-basic-01][Basicシーンを動作させた様子][scale=0.8]

右コントローラのトラックパッドの上にあるMenuボタンで位置のRecenterができます。
シーン内にも表示されていますが、「YVTuber」＞「Material」＞「manual」に簡単な操作方法を示す画像が入っていますので確認してください。
トラックパッドのクリックで手の形が、グリップ＋トラックパッドのクリックで表情モーフを切り替えることができます。
また、少々操作が難しいのですが、グリップで手と足を同期して動かすことができます。

以降、この「Basic」シーンをゼロから再現する手順と、その内容について説明していきます。

=== 3DモデルへのIK適用設定

まず、XR Mecanim IK Plusをモデルに適用します。

//image[yvtuber-basic-02][3つのPrefabをHierarchyに追加][scale=0.7]

 * メニューより、「File」「New Scene」を選択、"Hello"と入力し、新規シーンを作成します。
 * Projectタブより、「XR_MecanimIKPlus」＞「Prefabs」配下の「[XR CameraRig]」と「FloorAndMirror」をHierarchyに追加します。
 * Projectタブより、「youten-yume2」＞「youten-yume2」をHierarychyに追加し、「XR_MecanimIKPlus」配下の「Demo_IK_AnimatorController」Animator Controllerと、「Scripts」配下の「IK_Head_Linkage_CS」「IK_CS」「IK_Shoulder_Linkage_CS」Scriptをアタッチします。
 * 「IK_Head_Linkage_CS」のEye Transformには[XR CameraRig]配下の「Camera(eye）」を、Neck Transformにはモデルのボーン構造Armature配下の「Neck」を、Head Transformには「Head」を設定します。
 * 「IK_CS」の5つのターゲットには、[XR CameraRig]配下の「IK_Target_Body」「IK_Target_Hand_L」「IK_Target_Hand_R」「IK_Target_Foot_L」「IK_Target_Foot_R」をぞれぞれ設定します。
 * 「IK_Shoulder_Linkage_CS」の4つのターゲットにはモデル配下の「Left shoulder」「Right shoulder」「Left arm」「Right arm」をそれぞれ設定します。

//image[yvtuber-basic-03][Animator ControllerとXR Mecanim IK Plus 3つのScriptの設定][scale=0.8]

//image[yvtuber-basic-05][Unity標準Mecanim IKの利用には、Animator ControllerへのIK設定が必要][scale=0.7]

 XR Mecanim IK Plusの本家サイトでも説明がありますが、設定しているAnimator Controllerは空のものに、標準のMecanim IKを有効にする「IK Pass」のチェックを加えただけのものですので、他Animator Controllerに差し替える際には、同様にチェックを追加してください（@<img>{yvtuber-basic-05}）。

ここまで、3つのPrefab（@<img>{yvtuber-basic-02}）と、3つのScriptの設定（@<img>{yvtuber-basic-03}）が終わってUnityエディタにて再生すると、頭と手を動かすことができます。
また、グリップを組み合わせることにより、足も動かすことができます（@<img>{yvtuber-basic-04}）。

//image[yvtuber-basic-04][XR Mecanim IK Plusとモデルの紐づけ完了まで][scale=0.8]

=== XR API

Unity標準のXR APIとは、VR/AR/MRのさまざまなデバイスを統一的に扱うために定義されたAPI群です。
もともとは「VR API」という名前でしたが、Unity2017.2から「XR API」に変更されました。
ドキュメント中には「VR」という用語がそのまま残っているケースが多いです。

==== コントローラ入力

XR APIはさまざなXRデバイスに対応するために、最小限のプリミティブなAPIしか用意されておらず、そのコントローラ入力を取得するには、各プラットフォーム毎に設定を追加する必要があります。

具体的にはラッパーUtilクラスである「YVTuber」＞「Script」＞「XRVive」スクリプト内にコメントで記載していますが、Unity公式の「Input for OpenVR controllers」ドキュメント@<fn>{openvr-controllers}を参考に、Input Managerに設定を追加しています。

例えば、左コントローラのGripボタン「Left Controller Grip Button」は「Unity Axis IDが11」と記載されてていますので、「Edit」＞「Project Settings」＞「Input」のInput Manager設定に以下のように「Name」に"Grip L"、「Type」に「Joysticks Axis」、「Axis」に「11th axis（Joysticks）」を設定します。

こうすると、「Gripボタンが押されているか否か」は、「@<code>{if (Input.GetAxis("Grip L") > 0)}」といったコードで取得することができます。

//footnote[openvr-controllers][Unity - Manual: Input for OpenVR controllers @<href>{https://docs.unity3d.com/Manual/OpenVRControllers.html}]

==== トラッキングモード：立位とルームスケール

//image[yvtuber-basic-06][XR Basic Function Scriptのトラッキングモード設定][scale=0.8]

XR Mecanim IK Plusはデフォルトではトラッキングモードが「Stationary（立位モード）」になっています。
これは（名前が直観的ではないのですが）椅子などに座って行うのに適した方法で、右コントローラのMenuボタンに現在のヘッドセットの位置にあわせてリセットする「Recenter」が割り当てられています。

HTC Viveのルームスケールセットアップが有効であれば、これを「Room Scale（ルームスケール）」に変更することでルームスケールモードに切り替えることができます。
このモードではカメラを配置した座標がルーム内中央の地面に設定されますので、[XR Cameraig]のY座標を0にする他、利用している部屋にあわせて各オブジェクトの配置を調整してください。
また、ルームスケールモードではRecenterは動作しません。

=== リップシンク

続けて、リップシンクの実装です。
マイク入力音声から唇のモーフ制御を行うために、Oculus製の「OVRLipSync@<fn>{ovrlipsync}」というライブラリを使います。

//footnote[ovrlipsync][Oculus Lip Sync Unity Integration Guide @<href>{https://developer.oculus.com/documentation/audiosdk/latest/concepts/book-audio-ovrlipsync/}]

==== OVRLipSyncには手を入れています

配布されているOVRLipSync 1.16.0をベースに、以下のとおり改造したものをリポジトリに含めています。

 * マウス・キーボード入力によるデバッグ機能切り替えは誤爆回避のためコメントアウト。
 * 実行ウィンドウにフォーカスがないとマイク入力を一時停止する機能は不要のためコメントアウト。
 * 「OVRLipSync.cs」と「OVRLipSyncContext.cs」に初期化順番依存バグがあるため、「OVRLipSync.cs」の優先度を上げる
 ** @<code>{[DefaultExecutionOrder(-1)]}属性をクラスに追加。
 * 「LipSync_Demo」シーンの機能切り替え実装が煩雑で分かりづらいため、マイク入力によるモーフ制御のみに絞った「SimpleMicMorph_Demo」シーンを追加。
 * 副産物として、「OVRLipSyncMicInput」「OVRLipSyncContext」「OVRLipSyncContextTextureFlip」「OVRLipContextMorphTarget」スクリプトと付属の唇モデル向け設定を含む「InputType_Microphone」Prefabを追加。

このあたりの補足説明として、空のUnityプロジェクトから無改造のOVRLipSyncの使い方を一通り説明する動画をYouTubeにアップロードしています@<fn>{ovrlipsync-youtube}。

//footnote[ovrlipsync-youtube][OVRLipSync 1.16.0 + Unity 2017.3.1p4 - YouTube  @<href>{https://www.youtube.com/watch?v=OJwNNJuiBXw}]

==== モデルへのOVRLipSyncの適用

では、実際にOVRLipSyncを適用していきましょう。

 * Projectタブより、「OVRLipSync」＞「Prefabs」配下の「LipSyncInterface」と「InputType_Microphone」をHierarchyに追加します。
 * 「InputType_Micrphone」にアタッチされている「OVRLipContextMorphTarget」の「Skinned Mesh Renderer」に、モーフ制御対象のモデル配下の「Body」を設定します。
 * Viseme To Blend Targetsの配列に、15種類の口唇の形状にあわせた、モデルのモーフのindexを設定します。

15種類の口唇の形状（Viseme、ビゼーム）の仕様については、OVRLipSync公式ドキュメントの「Overview@<fn>{ovrlipsync-doc-overview}」に記載があります。詳細はリンクが貼られた「Viseme MPEG-4 Standard」のPDF内に、顔写真・対応する英単語とセットで一覧表が掲載されていますので、そちらで確認する必要があります。

大雑把には「Element 0」から順番に、「sil（無音、口を結ぶ）, PP, FF, TH, DD, kk, CH, SS, nn, RR（このあたり無清音、"無音"か"う"を適当に選択）, aa（あ）, E（え）, ih（い）, oh（お）, and ou（う）」のように設定します。

リポジトリに同梱している「youten-yume2」モデルはBlenderでの変換時にVRChat仕様（おそらくOVRLipSync仕様と同義）のモーフ設定がされていますので、そのままViseme名に対応したindexを設定します（@<img>{yvtuber-basic-08}）。

//image[yvtuber-basic-08][モデルのモーフと15種類のViseme設定の対応][scale=0.8]

//footnote[ovrlipsync-doc-overview][Overview  @<href>{https://developer.oculus.com/documentation/audiosdk/latest/concepts/audio-ovrlipsync-overview/}]

==== リップシンクがうまくいかない際の確認

OVRLipSyncが動かない際には、実行中に以下のポイントを確認してみてください（@<img>{yvtuber-basic-09}）。

 * 「OVRLipSyncMicInput」でマイクデバイスが正しく認識されているか。複数マイクの際には選択するなどが必要です。
 * 「OVRLipSyncContext」のAudio Muteチェックを外して、ループバック音声がきちんと聞こえるか。PC側の録音デバイスの設定を見直してください。
 * 「OVRLipSyncContextMorphTarget」に必要な設定が行われているか。
 * ターゲットの「Skinned Mesh Renderer」でモーフ制御が行われている様子が見られるか。0から100までの数字がきちんと変化しているのであれば、BlendShapeが対応しているかどうかのモデル側の話になります。

//image[yvtuber-basic-09][OVRLipSyncの動作確認ポイント][scale=1.0]

=== 自動まばたき

キャラクターが目を開けっぱなしで無表情だと、お面のように感じられて、かわいくありません。
自動でまばたきをするようにしましょう。

 * 「youten-yume2」に、「YVTuber」＞「AutoBlink」スクリプトをアタッチします。

dksjalさんのスクリプト@<fn>{dskjal-autoblink}をモデルに合わせて変更しています。
他のモデルで使う際にはまばたきモーフのindexと対象のSkinned Mesh Rendererを変更してください。

//footnote[dskjal-autoblink][ユニティちゃんの瞬きを滑らかにする @<href>{https://gist.github.com/dskjal/17034ad3b97bc6596248881f02caaafe}]

=== コントローラによる表情の変更

まばたきだけでもそれなりに人間っぽさが出ますが、表情をコントローラで制御できるようにしてみましょう。

 * Hierarchyより、「youten-yume2」に、「YVTuber」＞「MorphController」スクリプトをアタッチします。

モデルにあわせたモーフの処理については「Morph」スクリプトを、コントローラ入力の取得については「XRVive」スクリプトを参照願います。

//image[yvtuber-basic-10][コントローラによるモーフ制御][scale=0.70]

コントローラの後ろのトリガを押しながらトラックパッドを押し込むことでモーフを変化させることができます（@<img>{yvtuber-basic-10}）。
ちょっといじってみるとすぐ気づくと思いますが、今の実装はあまりよいものではありません。

そもそもの話として、顔の表情を手で操作するということが直感的ではありません。
また、Viveコントローラのトラックパッドに少々癖があり、タップしてからスライドするとやっとタッチイベントが発生するようなことがあります。
ジト目や笑顔目のようなふんだんに使っても自然であるモーフと、「＞＜」目や瞳がキュツと小さくなるようなマンガ的な表現の特別なモーフを同じ操作体系に組み込んでしまっているため、誤爆しやすく、その際には違和感が強く出てしまいます。

前章で紹介したアイトラッキング技術と、個人の目の大きさや笑顔の個人差をうまく吸収できるような機械学習ベースの仕組みに、マンガ的な大げさな、効果的な演出が重ねられるようになるまではこのモーフ制御というのは難しいジャンルなのかな、と思います。

=== コントローラによる手のポーズ制御

続けて、手のポーズをコントローラで制御できるようにしてみましょう。

//image[yvtuber-basic-12][手のポーズ。左右で鏡になる操作系になっている。][scale=0.70]

//image[yvtuber-basic-11][Animator Controllerの設定変更][scale=0.70]

 * Hierarchy中の「youten-yume2」を選択し、「Animator」コンポーネントの「Controller」を「HandPoses」＞「HandPosesController」を設定します。（@<img>{yvtuber-basic-11}）
 * Hierarchy中の「youten-yume2」に、「YVTuber」＞「HandController」スクリプトをアタッチします。

 コントローラのトラックパッドをタッチすることで、手のポーズを変化させることができます（@<img>{yvtuber-basic-12}）。
 色々な手の形を詰め込んだアニメーションパックは@m2wasabiさんの「HandPose 0.2.0」を使わせていただいています。

=== ビルド

ビルドについては、実のところ必須ではありません。
結局のところ録画目的でも、配信目的でも、ウィンドウキャプチャが主流ですので、Unityエディタ上での再生のみでも問題ないケースがあります。

主なビルドのメリットはパフォーマンスの観点で優れていることと、配布がしやすくなることです。
逆にデメリットはUnityエディタのように、実行中にHierarchyやパラメータの操作はできないことです。

//image[yvtuber-build][ビルドした上でウィンドウモードで起動したYVTuber][scale=0.6]

ビルドして実行後、画面解像度を選択して起動し、エディタ上での再生と同じように各機能が動くことを確認します（@<img>{yvtuber-build}）。

== 撮影と編集

前節までの手順で、ビルドしたexeにてVTuberらしき画が出せるようになりましたので、撮影と編集を行なって、動画を作ってみましょう。

===  OBS（Open Broadcaster Software） Studioでの撮影

デスクトップ、特定のウィンドウ、フルスクリーンのゲームなど多様な画面キャプチャ機能を持ち、録画・エンコード・配信を一気に引き受ける、OBS（Open Broadcaster Software）Studio@<fn>{obs-studio}というフリーソフトがあります。

TwichやYouTubeLive他、各配信サービスに対応しており、クロマキーなどのフィルタエフェクトを含む優れたレイヤー機能があり、大変人気のソフトです。
そのため、インターネットで検索すると初心者向けから上級者向けまでたくさんの情報が見つかりますすので、詳しい使い方はそちらを参照願います。

筆者が一つだけつまづいたのは一番最初のインストーラのダウンロードで、配布サーバがあまり強くないのかダウンロードできないケースがよくある模様です。
BitTorrentで別経路からダウンロードしてうまくいきました。

//image[obs-01][OBS（Open Broadcaster Software） Studio][scale=0.7]

YVTuberを起動した状態でOBSを起動し、画面下部のソースから対象ウィンドウと切り抜き範囲などを適当に設定するとOBS側で画が見えるようになります(@<img>{obs-01})。
「録画開始」ボタンを押すと、録画が出力されはじめます。

後で編集することを想定している際には、劣化しないAVI形式の動画が望ましいです。
「UtVideo@<fn>{utvideo}」という可逆圧縮フォーマットのコーデックがありまして、無圧縮（≒連続BMP）のAVIとほぼ同等に扱えながら、ファイルサイズを大幅に削減できますのでオススメです。

//footnote[obs-studio][Open Broadcaster Software | ホーム @<href>{https://obsproject.com/ja}]
//footnote[utvideo][或るプログラマの一生 » Ut Video Codec Suite @<href>{http://umezawa.dyndns.info/wordpress/?cat=28}]

=== AviUtlと拡張編集プラグインでの字幕つけ

それでは、動画編集を行なっていきましょう。
テンポが良く、情報密度の高い動画を作るには、やはり字幕芸がてっとり早いです。

画像（文字）は音声と比較して情報を取得するのに必要な時間が短く、閲覧のコストを下げてくれるよいものです。
テレビのバラエティで当たり前のように浸透し、niconico・YouTuberなどの文化にてさらに映像ごと無音を詰めるスタイルも確立され、多くのバーチャルYouTuberの方々も、先駆者のキズナアイさんに倣って同様のスタイルを採っています。

//image[aviutl-02][AviUtlメイン画面][scale=0.6]

動画編集ソフトについては、キャプチャ・配信のOBSと比較すると選択肢が多く、良いものが複数ある印象です。
「無料ながら高機能」「プラグイン形式での機能拡張と、その情報の手に入りやすさ」で一時代を築いた@<fn>{aviutl-history}「AviUtl@<fn>{aviutl}」が今でも現役なようで、これでよさそうです。

//footnote[aviutl][AviUtlのお部屋 @<href>{http://spring-fragrance.mints.ne.jp/aviutl/}]
//footnote[aviutl-history][ROのGvG動画をzoomeに、FEZの部隊訓練動画をstage6に、MMD動画をniconicoに…]

//image[aviutl-03][LargeAddressAware設定による利用可能なメモリサイズ増加設定][scale=0.6]

AviUtlは残念ながら32bitアプリのため、扱えるメモリサイズに限界があります。
デフォルト2GBの上限を4GBまで引き上げるLargeAddressAwareの有効化は最初にやっておいたほうがいいでしょう。
根本的には解決していない問題のため、大きなプロジェクトを扱う際には工程やシーンの分割などの泥臭い対応が必要になります。

//image[aviutl-04-05][拡張編集のタイムラインとテキスト][scale=0.7]

拡張編集のタイムラインにAVIを読み込んで、ゴリゴリと字幕をつけていきます。
タイムラインで「メディアオブジェクトの追加」から「テキスト」を選択してフォントサイズと縁取り設定をすると、それっぽい字幕をつけられます（@<img>{aviutl-04-05}）。

実際にYVTuberシステムで動画を撮って、OBSで撮影し、AviUtlで字幕をつけたサンプル動画をYouTubeにアップロードしています@<fn>{yvtuber-sample-movie}。
エンコードには「x264guiEx@<fn>{x264guiex}」を使っています。

こちらの約1分半の尺の動画で、撮影からYouTubeへの投稿完了まで1時間半程度かかりました。

コツというか、実際にやってみた感想なのですが、喋る内容の脚本を予め書いた上で、字幕や画像をどのように埋めるのかを予め想定しながら読み上げ練習をしておくと、録画の成功率が上がります。
いわゆる「絵コンテの作成」や「読み合わせ」にあたるものです。

また、最初は1分程度の短い動画からチャレンジすることをオススメします@<fn>{short-movie}。
実際に撮影する前に練っておくことで脱線を防ぐことができ、脚本のテキストがそのまま字幕に使えるようになり、動画の編集効率がよくなります。

//footnote[yvtuber-sample-movie][【YVTuber】VTuberシステムを作ってみた話の同人誌【サンプル動画】 - YouTube @<href>{https://www.youtube.com/watch?v=xFWbyAc0VK0}]
//footnote[x264guiex][rigayaの日記兼メモ帳 x264guiEx 1.xx/2.xx 導入 @<href>{https://rigaya34589.blog.fc2.com/blog-entry-139.html}]
//footnote[short-movie][いきなり5分超えで収録したところ、編集に時間がかかりすぎで泣きました。本職の人マジ尊敬します…]

== その他の機能の実装例

基本編は以上ということで、その他の機能の実装例を紹介します。

=== グリーンバックによるアバターの切り抜き

グリーンバックによるアバター切り抜きも簡単です。

Unity側でグリーンバックのPlaneを準備して、OBS側でクロマキー設定をしましょう。
手順は次のとおりです。

//image[greenback-02-03][Unityにてアバターの後ろにグリーンバックを設定し、OBSにてソースにエフェクトフィルタを追加][scale=0.6]

 * UnityでHierarchyタブにて、「Create」＞「3D Object」＞「Plane」で平面を用意します。"GreenBack"あたりの名前に変えておきましょう。
 * Projectタブにて、「Create」＞「Material」で新規Materialを作成し、名前は"green"にします。Inspectorタブから、「Shader」を「Unlit/Color」に変更し、「Main Color」を緑（RGBA = 0,255,0,255）に設定します。
 * 作成したPlaneにMaterialを設定し、適切な位置に回転して移動させてください（@<img>{greenback-02-03}）。
 * 続けてOBSで、アバターの映っているYVTuberウィンドウを右クリックし、フィルタを選択します（@<img>{greenback-02-03}）。
 * 新しく開いたフィルタ設定ウィンドウにて、左下の「＋」からクロマキーを追加します。グリーンバックと書きましたが、青やマゼンダで切り抜くこともできます。

//image[greenback-05][クロマキー合成後の画][scale=0.7]

このように、だいたいどんなシーンでも自由に作ることができるUnityと、サイズ調整・配置・レイヤー制御・クロマキーなどのフィルタが揃ったOBSを組み合わせると、録画・配信問わず自由度の高い画を作り出すことができます（@<img>{greenback-05}）。

これ以降については、Unityや動画編集の技術としてたくさんの情報がインターネットや書籍で手に入りますので、そちらを参照願います。

=== UnityCamでカメラ出力

続いて、ウィンドウへの出力ではなく、カメラデバイスとしての画面出力機能を追加してみましょう。
これができると、Hangoutなどのカメラデバイスが選択できるテレビ電話アプリで、バーチャルアバターを使うことができます。

「UnityCam@<fn>{unitycam}」を使うと、仮想のカメラデバイスに対してUnity内のカメラ映像を流し込むことができます。

//footnote[unitycam][mrayy/UnityCam: Unity3D Virtual webcam plugin, streams unity viewport contents to other applications as virtual camera @<href>{https://github.com/mrayy/UnityCam}]

==== 仮想カメラデバイスのセットアップ

「UnityCam/RunMe First」配下に「UnityCameraService.dll」という仮想カメラデバイスがありますので、「register.bat」を実行して登録しましょう。
カメラドライバはインストールすればWindowsシステム全体で共通して利用できるため、このフォルダはUnityプロジェクト配下ではなく、どこかPC上の別のパスに配置の上registerした方が良いと思われます。

==== 必要なファイル一式をexportして目的のプロジェクトでimport

UnityCamを本書で作成したVTuberシステムのシーンに適用してみましょう。

次のとおりの手順となります。

//image[unitycam-02][UnityCamプロジェクトから必要なファイル一式をexport][scale=0.70]

 * 「UnityCam」リポジトリ一式をダウンロードし、「RunMe First」配下のdll登録バッチファイルを実行します。
 * 「UnityCam/UnitySample」プロジェクトを開き、「UnityCam」と「Plugins」を右クリックして「Export Package...」を選択、依存関係含め一式が選択されているのを確認して、unitypackageとして「Export」します（@<img>{unitycam-02}）。
 * 適用するYVTuberプロジェクトに戻って、exportしたunitypackageをimportします。
 * 出力対象のカメラ、ここではHierarchyより「FloorAndMirror」＞「Camera_Movie」に「UnityCam」＞「Scripts」＞「UnityCam」スクリプトをアタッチします。

//image[hangout-01][HangoutプレビューでのUnityCamによるYVTuberの出力][scale=0.6]

Unityを実行すると、仮想カメラデバイスからUnityCamで流した画が表示されているはずです。
カメラ画像のプレビューなどが確認できるアプリを動かしてみましょう。
他のWebカメラと同様のしくみで動いていますので、ブラウザで動くテレビ電話アプリであるHangoutでもこのようにバーチャルアバターを使うことができます。

==== UnityCamのデメリットとOBS-VirtualCam

カメラが扱えるアプリであればアバターの画が取れるようになり、汎用性が上がるUnityCamの導入ですが、どうも解像度とFPSの上限がdll側で決められているようです（@<fn>{unitycam-service-resolution}）。
また、それなりに負荷が高いことが知られており、とくに録画目的ではOBSなどのウィンドウキャプチャの方が向いていると言われています。

では、Unity側ではなく、OBS側で合成した画像を仮想カメラデバイスに流す方法がないのかと調べてみたところ、「OBS-VirtualCam@<fn>{obs-virtualcam}」というそのまんまの名前のプラグインがありました。

//image[obs-virtualcam-01][OBS-VirtualCam][scale=0.7]

インストールして、OBSのメニュー「ツール」＞「VirtualCam」で動作させることができます。
間に挟むアプリが増えるので手間は増えてしまいますが、OBS側のレイヤー合成結果ができることが最大のメリットといえるでしょう。

結論としてはどちらにもメリットがあるため、用途にあわせて使い分けるのがよさそうです。

//footnote[unitycam-service-resolution][@<href>{https://github.com/mrayy/UnityCam/blob/master/UnityWebcam/UnityCamService/CaptureSource.cpp}]
//footnote[obs-virtualcam][OBS-VirtualCam | Open Broadcaster Software @<href>{https://obsproject.com/forum/resources/obs-virtualcam.539/}]

=== Tracker対応と両足のトラッキング

XR Mecanim IK PlusにはHTC ViveコントローラのGripボタンによる手と足を同期させて両方動かす機能があるのですが、その代わりにHTC Vive Trackerの座標を設定してやれば、両足も動かせるのでは、と試してみました。

==== 作りかけのサンダル

「YVTuber」直下に「WithTrackerSandal」という作りかけ（すいません）のシーンがありますのでそちらを参照願います。
高さやスクリーンの座標調整が不十分であったり、Unityエディタ内で起動後にTrackerのidを手動で設定してやる必要がありますが、一応最低限は動作します。

//image[tracker-01][XRDeviceTrackerスクリプトとアタッチ・設定例][scale=0.7]

Hierarchy中にそれぞれ「裸のTracker」・「Trackerを取り付けたサンダル左足」・「Trackerを取り付けたサンダル右足」に対応する、「Tracker」・「LeftSandal」・「RightSandal」というオブジェクトを配置しています。
ここにアタッチされた「YVTuber」＞「Script」＞「XRDeviceTracker」スクリプトがAPI @<code>{InputTracking.GetNodeStates(List<XR.XRNodeState>)}によってTrackerの現実空間上の座標を取得し、対象のTransformへ座標を転送します（@<img>{tracker-01}）。

==== XR APIとトラッキングモードの注意

 @<code>{InputTracking.GetNodeStates(List<XR.XRNodeState>)}は、原点位置からの相対座標を返すため、本章の頭の方で述べたトラッキングモードがルームスケールでない際には正しく動きません。
きちんと対応するのであれば、立位モードの際にはRecenter操作のタイミングで、リセットした座標を差し引く必要があると思われます。

本プロジェクトをベースにTrackerを扱う際には、「[XR CameraRig]」にアタッチされた「XR_Basic_Function_CS」中の「Tracing Space Type」を「Room Scale」に設定した上であれこれ試してみてください。

== まとめ

本誌のメインであるこの章ですが、「Hello, VTuber World!」の副題の通り、あくまでHello Worldとして、とくに難しいことはしておりません。
ここから先は、他のVTuberの方々が実施されているように、世界観を作り込んでいく作業が丸々と残っています。

モデル・音声・脚本などのキャラクターを構成する要素は仮のものですし、Asset Storeの豊富なアセットは背景、小物、エフェクト含め一切使っておらず、いわゆる「演出」がゼロの状態です。
完成品としての作品やサービスを創り上げた経験がほとんどない筆者の現時点での限界でもありますし、今後はそのあたりをきちんと盛って、きちんと「VTuber」になれたら面白いのでがんばってみたいな、と考えています。
